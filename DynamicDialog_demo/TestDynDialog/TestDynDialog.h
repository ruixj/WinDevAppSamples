// TestDynDialog.h : main header file for the TESTDYNDIALOG application
//

#if !defined(AFX_TESTDYNDIALOG_H__5A8CE59A_B653_4EE7_BC10_CE7671A5660E__INCLUDED_)
#define AFX_TESTDYNDIALOG_H__5A8CE59A_B653_4EE7_BC10_CE7671A5660E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestDynDialogApp:
// See TestDynDialog.cpp for the implementation of this class
//

class CTestDynDialogApp : public CWinApp
{
public:
	CTestDynDialogApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDynDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestDynDialogApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDYNDIALOG_H__5A8CE59A_B653_4EE7_BC10_CE7671A5660E__INCLUDED_)
