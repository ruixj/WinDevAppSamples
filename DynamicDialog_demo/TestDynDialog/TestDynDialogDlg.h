// TestDynDialogDlg.h : header file
//

#if !defined(AFX_TESTDYNDIALOGDLG_H__1C89F7A5_A628_4D27_A70C_89B8397A0DFD__INCLUDED_)
#define AFX_TESTDYNDIALOGDLG_H__1C89F7A5_A628_4D27_A70C_89B8397A0DFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestDynDialogDlg dialog

class CTestDynDialogDlg : public CDialog
{
// Construction
public:
	CTestDynDialogDlg(CWnd* pParent = NULL);	// standard constructor
	~CTestDynDialogDlg();

// Dialog Data
	//{{AFX_DATA(CTestDynDialogDlg)
	enum { IDD = IDD_TESTDYNDIALOG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDynDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	void DestroyModelessDialog();
	HICON m_hIcon;
	CDialog *m_pDialog;

	// Generated message map functions
	//{{AFX_MSG(CTestDynDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDYNDIALOGDLG_H__1C89F7A5_A628_4D27_A70C_89B8397A0DFD__INCLUDED_)
