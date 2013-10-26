// gditest1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "gditest1.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_GDITEST1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GDITEST1));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GDITEST1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_GDITEST1);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
    //POINT Pt[7];
    //Pt[0].x = 20;  Pt[0].y = 50;
    //Pt[1].x = 180; Pt[1].y = 50;
    //Pt[2].x = 180; Pt[2].y = 20;
    //Pt[3].x = 230; Pt[3].y = 70;
    //Pt[4].x = 180; Pt[4].y = 120;
    //Pt[5].x = 180; Pt[5].y = 90;
    //Pt[6].x = 20;  Pt[6].y = 90;


 //POINT Pt[15];
	//DWORD  lpPts[] = { 4, 4, 7 };

	//// Left Triangle
	//Pt[0].x = 50;
	//Pt[0].y = 20;
	//Pt[1].x = 20;
	//Pt[1].y = 60;
	//Pt[2].x = 80;
	//Pt[2].y = 60;
	//Pt[3].x = 50;
	//Pt[3].y = 20;
	//
	//// Second Triangle
	//Pt[4].x =  70;
	//Pt[4].y =  20;
	//Pt[5].x = 100;
	//Pt[5].y =  60;
	//Pt[6].x = 130;
	//Pt[6].y =  20;
	//Pt[7].x =  70;
	//Pt[7].y =  20;

	//// Hexagon
	//Pt[8].x  = 145;
	//Pt[8].y  =  20;
	//Pt[9].x  = 130;
	//Pt[9].y  =  40;
	//Pt[10].x = 145;
	//Pt[10].y =  60;
	//Pt[11].x = 165;
	//Pt[11].y =  60;
	//Pt[12].x = 180;
	//Pt[12].y =  40;
	//Pt[13].x = 165;
	//Pt[13].y =  20;
	//Pt[14].x = 145;
	//Pt[14].y =  20;


 //  POINT Pt[7];
	//Pt[0].x =  20;
	//Pt[0].y =  50;
	//Pt[1].x = 180;
	//Pt[1].y =  50;
	//Pt[2].x = 180;
	//Pt[2].y =  20;
	//Pt[3].x = 230;
	//Pt[3].y =  70;
	//Pt[4].x = 180;
	//Pt[4].y = 120;
	//Pt[5].x = 180;
	//Pt[5].y =  90;
	//Pt[6].x =  20;
	//Pt[6].y =  90;

	RECT RectTo = {20, 20, 225, 115 };

	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		//MoveToEx(hdc, 60, 20, NULL);
		//LineTo(hdc, 60, 122);
		//LineTo(hdc, 264, 122);
		//LineTo(hdc, 60, 20);

		//Polyline(hdc, Pt, 7);

        //PolyPolyline(hdc, Pt, lpPts, 3);

		//Polygon(hdc, Pt, 7);

		//DrawEdge(hdc, &RectTo, BDR_SUNKENOUTER | BDR_SUNKENINNER, BF_RECT);

		//Ellipse(hdc, 50, 100, 150, 200);

		//RoundRect(hdc, 10, 10, 50, 50, 15, 30);

		Pie(hdc, 40, 20, 226, 144, 155, 32, 202, 115);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
