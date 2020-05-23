// MFCLibrary.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "MFCLibrary.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CMFCLibraryApp

BEGIN_MESSAGE_MAP(CMFCLibraryApp, CWinApp)
END_MESSAGE_MAP()


// CMFCLibraryApp construction

CMFCLibraryApp::CMFCLibraryApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CMFCLibraryApp object

CMFCLibraryApp theApp;


// CMFCLibraryApp initialization

BOOL CMFCLibraryApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

typedef struct MyType {
	int i;
	char *s;
	struct MyType *p;
} MyType;

void CallbackTest(void(__stdcall *printMessage)(WCHAR *wChar))
{
	(*printMessage)(L"Reserve P/Invoke interop debugging");	// Reverse here
}

int StrTrick(char *str)
{
	int count[3];
	memset(count, 0, 3 * sizeof(int));
	int value = 0;
	char currentStr = '0'; // Entry of loop
	while (*str != 0)
	{
		currentStr = *str;
		if (*str >= '0' && *str <= '9')
		{
			count[0]++;
		}
		else if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		{
			count[1]++;
		}
		else
		{
			count[2]++;
		}
		str++;
		value++;
		if (value == 3)
		{
			break;  // Break function
		}
	}

	return count[1]; // Last line of function
}

