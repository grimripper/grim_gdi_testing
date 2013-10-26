#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <process.h>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

/* buffer using a shared integer variable */

void delay(int secs) 
{ /*utility function*/
	time_t beg = time(NULL), end = beg + secs;
	do 
	{
		;
	} while (time(NULL) < end);
}


class Point
{
public:
	int x,y;
};

vector<shared_ptr<Point>> pointVec;

// ALGO 1

CRITICAL_SECTION cs;
CONDITION_VARIABLE mReady;
bool ready = false;

int store1(const shared_ptr<Point>& pPoint) 
{
	EnterCriticalSection(&cs);

	pointVec.push_back(pPoint);
	cout << "ptr ref count = " << pPoint.use_count() << endl;

	WakeConditionVariable(&mReady);    //signal
	LeaveCriticalSection(&cs);
	return 0;
}

bool shouldQuit = false;

DWORD WINAPI consumer1(void *n) 
{
	int j=0, tot=0;
	while (j < 10) 
	{
		EnterCriticalSection(&cs);
		while (!shouldQuit && pointVec.empty()) 
		{
			SleepConditionVariableCS(&mReady, &cs, INFINITE);
		}
		if (shouldQuit)
		{
			cout << "goodbye" << endl;
			break; 
		}

		vector<shared_ptr<Point>> mypointvec;
		mypointvec.swap(pointVec);
		LeaveCriticalSection(&cs);

		for (int i = 0; i < mypointvec.size(); ++i)
		{
			cout << mypointvec[i]->x << " " << mypointvec[i]->y << endl;
		}
	}
	printf("Retrieved total = %d; \n", tot);
	return 1;
}

// ALGO 2

HANDLE kill;
HANDLE mutex;
HANDLE sem;
int store2(const shared_ptr<Point>& pPoint) 
{
	WaitForSingleObject(mutex, INFINITE);
	pointVec.push_back(pPoint);
	cout << "ptr ref count = " << pPoint.use_count() << endl;

	if (pointVec.size() > 0)
	{
		long semCount;
		ReleaseSemaphore(sem, 1, &semCount);
		//cout << "semCount = " << semCount << endl;
	}
	ReleaseMutex(mutex);
	return 0;
}

DWORD WINAPI consumer2(void *n)
{
	int j=0, tot=0;
	while (j < 10) 
	{
		vector<shared_ptr<Point>> mypointvec;
		HANDLE handles[] = { kill, sem };
		int waitObject = WaitForMultipleObjects(2, handles, false, INFINITE);
		if (waitObject == WAIT_OBJECT_0)
		{
			break;
		}
		WaitForSingleObject(mutex, INFINITE);
		mypointvec.swap(pointVec);
		ReleaseMutex(mutex);

		delay(3);
		for (int i = 0; i < mypointvec.size(); ++i)
		{
			cout << mypointvec[i]->x << " " << mypointvec[i]->y << endl;
		}
	}
	printf("Retrieved total = %d; \n", tot);
	return 1;
}



int main() 
{
	DWORD prodThrdID, consThrdID;
	srand(time(NULL)); /* initialise the rng */
	//InitializeCriticalSection(&cs);
	//InitializeConditionVariable(&mReady);
	//HANDLE h1 = CreateThread(NULL, 0, consumer1, NULL, 0, NULL);
	mutex = CreateMutex(NULL, false, NULL);
	sem = CreateSemaphore(NULL,0,1,NULL);
	kill = CreateEvent(NULL, FALSE, FALSE, NULL);
	HANDLE h2 = CreateThread(NULL, 0, consumer2, NULL, 0, NULL);

	int x,y;
	while (cin >> x >> y)
	{
		shared_ptr<Point> ptr(new Point());
		ptr->x = x;
		ptr->y = y;
		//cout << "ptr ref count = " << ptr.use_count() << endl;

		if (x == 4 && y == 4)
		{
			//shouldQuit = true;
			//WakeConditionVariable(&mReady);
			//WaitForSingleObjectEx(h1, INFINITE, TRUE);

			SetEvent(kill);
			WaitForSingleObjectEx(h2, INFINITE, TRUE);
			break;
		}

		//store1(ptr);
		store2(ptr);
	}

	//while (!prodDone || !consDone)
	//; 
	getchar();
	return 0;
}