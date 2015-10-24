// TestDynDialogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestDynDialog.h"
#include "TestDynDialogDlg.h"

#include "DynDialogEx.h"
#include "ListDynDialogEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


UINT ProcessDlgFunc(LPVOID in)  
{  
	CProgressCtrl *pProgressCtrl = (CProgressCtrl *)in;  
  
    int count = 0;  
    while(count++ <= 100)  
    {  
        pProgressCtrl->SetPos (count);
        
    }  
	return 0;
}  



/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDynDialogDlg dialog

CTestDynDialogDlg::CTestDynDialogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDynDialogDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDynDialogDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pDialog = NULL;
	m_progress = NULL;
}

CTestDynDialogDlg::~CTestDynDialogDlg()
{
	DestroyModelessDialog();
	delete[] m_progress;
}

void CTestDynDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDynDialogDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDynDialogDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDynDialogDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDynDialogDlg message handlers

BOOL CTestDynDialogDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestDynDialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestDynDialogDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestDynDialogDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

#define IDC_DYN_BUTTON	250	

void CTestDynDialogDlg::OnButton1() 
{
	int nRadio1 = 0;
	int nRadio2 = 0;
	int rc;
	BOOL bCheck = FALSE;
	CString strEditBuf(_T("Edit me"));
	CRect rect(10,5,60,19);

	CDynDialogEx dlg(this);		//create the dynamic dialog, using this as parent window

	dlg.SetWindowTitle(_T("Dynamic Dialog : WindowTitle....."));

	//Add a button control at the given position
	dlg.AddDlgControl(_T("BUTTON"),			// Type of control OR classname of the control
							_T("Press me!"),		// Caption of control
							STYLE_BUTTON,			// dwStyle of control
							EXSTYLE_BUTTON,		// dwStyleEx of control
							&rect,					// Position of control on dialog in dialog units, default = NULL
							NULL,						// void pointer to variable use for DDX, default = NULL
							IDC_DYN_BUTTON);		// ID of the contol, default = zero

	//Add a group of radio buttons,
	//variable nRadio1 is used for DDX
	dlg.AddDlgControl(_T("BUTTON"), _T("Radio1Caption 1"), STYLE_RADIO_GROUP, EXSTYLE_RADIO, NULL, (void*)&nRadio1);
	dlg.AddDlgControl(_T("BUTTON"), _T("Radio1Caption 2"), STYLE_RADIO, EXSTYLE_RADIO);

	m_progress = new CProgressCtrl[2];
	dlg.AddDlgControl(_T("msctls_progress32"), _T("1"), WS_VISIBLE | WS_CHILD | WS_TABSTOP | WS_BORDER, 0,NULL,&m_progress[0]);
	 dlg.AddDlgControl(_T("msctls_progress32"), _T("2"), WS_VISIBLE | WS_CHILD | WS_TABSTOP | WS_BORDER, 0,NULL,&m_progress[1]);
	//Add a another group of radio buttons
	//variable nRadio2 is used for DDX
	dlg.AddDlgControl(_T("BUTTON"), _T("Radio2Caption 1"), STYLE_RADIO_GROUP, EXSTYLE_RADIO, NULL, (void*)&nRadio2);
	dlg.AddDlgControl(_T("BUTTON"), _T("Radio2Caption 2"), STYLE_RADIO, EXSTYLE_RADIO);

	//Add a checkbox with the group style set, so the radio button group ends.
	dlg.AddDlgControl(_T("BUTTON"), _T("Check Caption"), (STYLE_CHECKBOX | WS_GROUP), EXSTYLE_CHECKBOX, NULL, (void*)&bCheck);

	//Add a edit control
	dlg.AddDlgControl(_T("EDIT"), _T(""), STYLE_EDIT, EXSTYLE_EDIT, NULL, (void*)&strEditBuf);

	//Now show me the dialog

		rc = dlg.DoModal() ;

	 if (rc == IDOK) {
		CString strResults;
		strResults.Format(_T("Pressed OK. Inputvalues:"
									"nRadio1 = %d\n"
									"nRadio2 = %d\n"
									"bCheck = %s\n"
									"strEditBuf = %s"),
									nRadio1, nRadio2, bCheck ? "TRUE" : "FALSE", strEditBuf);
		AfxMessageBox(strResults);

	}
	else {
		AfxMessageBox(_T("Pressed Cancel."));
	}
}

BOOL CTestDynDialogDlg::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	//wParam
	//The low-order word of wParam identifies the command ID of the menu item, control, or accelerator.
	//The high-order word of wParam specifies the notification message if the message is from a control.
	//If the message is from an accelerator, the high-order word is 1.
	//If the message is from a menu, the high-order word is 0.

	//lParam
	//Identifies the control that sends the message if the message is from a control. Otherwise, lParam is 0.

	WORD wControlID = LOWORD(wParam);
	WORD wMessageID = HIWORD(wParam);
	CRect   rcTemp;
	int   cx,cy;
	if (wControlID != 0) {
		switch (wControlID) {
		case IDC_DYN_BUTTON:
			//AfxMessageBox(_T("You pressed the button"));
			AfxBeginThread(ProcessDlgFunc, &m_progress[0]);  
			AfxBeginThread(ProcessDlgFunc, &m_progress[1]); 
			break;
		default:
			break;
		}
	}

	return CDialog::OnCommand(wParam, lParam);
}

void CTestDynDialogDlg::OnButton2() 
{
	CDynDialogEx dlg(this);
	int nRadio1 = 0;
	int nRadio2 = 0;
	BOOL bCheck = FALSE;
	CString strEditBuf(_T("Excalibur"));

	dlg.AddDlgControl(_T("BUTTON"), _T("ButtonCaption"), STYLE_BUTTON, EXSTYLE_BUTTON);
	dlg.AddDlgControl(_T("BUTTON"), _T("Radio1Caption 1"), STYLE_RADIO_GROUP, EXSTYLE_RADIO, NULL, (void*)&nRadio1);
	dlg.AddDlgControl(_T("BUTTON"), _T("Radio1Caption 2"), STYLE_RADIO, EXSTYLE_RADIO);
	dlg.AddDlgControl(_T("BUTTON"), _T("Radio2Caption 1"), STYLE_RADIO_GROUP, EXSTYLE_RADIO, NULL, (void*)&nRadio2);
	dlg.AddDlgControl(_T("BUTTON"), _T("Radio2Caption 2"), STYLE_RADIO, EXSTYLE_RADIO);
	dlg.AddDlgControl(_T("BUTTON"), _T("Check Caption"), (STYLE_CHECKBOX | WS_GROUP), EXSTYLE_CHECKBOX, NULL, (void*)&bCheck);

	dlg.AddDlgControl(_T("EDIT"), _T(""), STYLE_EDIT, EXSTYLE_EDIT, NULL, (void*)&strEditBuf);
	dlg.AddDlgControl(_T("EDIT"), _T(""), STYLE_MULTIEDIT, EXSTYLE_MULTIEDIT, NULL, (void*)&strEditBuf);

	dlg.AddDlgControl(_T("STATIC"), _T("StaticText"), STYLE_STATIC, EXSTYLE_STATIC);
	dlg.AddDlgControl(_T("STATIC"), _T("StaticFrame"), STYLE_STATIC | SS_BLACKFRAME, EXSTYLE_STATIC);

	dlg.AddDlgControl(_T("BUTTON"), _T("StaticFrame"), STYLE_GROUPBOX, EXSTYLE_GROUPBOX);

	dlg.AddDlgControl(_T("LISTBOX"), _T("ListboxText"), STYLE_MULTIEDIT, EXSTYLE_MULTIEDIT);

	dlg.AddDlgControl(_T("COMBOBOX"), _T("DropDownComboText"), STYLE_COMBOBOX_DROPDOWN, EXSTYLE_COMBOBOX /*, NULL, (void*)&cCombo*/);
	dlg.AddDlgControl(_T("COMBOBOX"), _T("SimpleComboText"), STYLE_COMBOBOX_SIMPLE, EXSTYLE_COMBOBOX);
	dlg.AddDlgControl(_T("COMBOBOX"), _T("DropDownListComboText"), STYLE_COMBOBOX_DROPDOWNLIST, EXSTYLE_COMBOBOX);

	dlg.AddDlgControl(_T("msctls_updown32"), _T(""), WS_VISIBLE | WS_CHILD | WS_TABSTOP | UDS_ARROWKEYS, 0);

	dlg.AddDlgControl(_T("msctls_progress32"), _T(""), WS_VISIBLE | WS_CHILD | WS_TABSTOP | WS_BORDER, 0);

	dlg.AddDlgControl(_T("msctls_trackbar32"), _T(""), WS_VISIBLE | WS_CHILD | TBS_BOTH | WS_TABSTOP | TBS_NOTICKS, 0);

	dlg.AddDlgControl(_T("msctls_hotkey32"), _T(""), WS_VISIBLE | WS_CHILD | WS_TABSTOP | WS_BORDER, 0);

	dlg.AddDlgControl(_T("SysListView32"), _T(""), WS_VISIBLE | WS_CHILD | WS_TABSTOP | WS_BORDER | LVS_SINGLESEL, 0);

	dlg.AddDlgControl(_T("SysTreeView32"), _T(""), WS_VISIBLE | WS_CHILD | WS_TABSTOP | WS_BORDER, 0);

	dlg.AddDlgControl(_T("SysTabControl32"), _T("Tab 1 Text"), WS_VISIBLE | WS_CHILD | WS_TABSTOP | WS_BORDER, 0);

	dlg.AddDlgControl(_T("SysAnimate32"), _T("SysAnimate Text"), WS_VISIBLE | WS_CHILD | WS_TABSTOP | WS_BORDER, 0);

	dlg.AddDlgControl(_T("SysDateTimePick32"), _T(""), WS_VISIBLE | WS_CHILD | WS_TABSTOP | DTS_RIGHTALIGN, 0);

	dlg.AddDlgControl(_T("SysMonthCal32"), _T(""), WS_VISIBLE | WS_CHILD | WS_TABSTOP | MCS_NOTODAY, 0);

	dlg.AddDlgControl(_T("SysIPAddress32"), _T(""), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 0);

	dlg.AddDlgControl(_T("ComboBoxEx32"), _T(""), WS_VISIBLE | WS_CHILD | CBS_DROPDOWN | CBS_SORT | WS_VSCROLL | WS_TABSTOP, 0);

	dlg.SetWindowTitle(_T("Dynamic Dialog : ALL CONTROLS DYNAMICLY CREATED !!!"));

	dlg.DoModal();
}

void CTestDynDialogDlg::OnButton3() 
{
	if (m_pDialog == NULL) {
		int nRadio1 = 0;
		CRect rect(10,5,60,19);

		CDynDialogEx *pdlg = new CDynDialogEx(this);		//create the dynamic dialog, using this as parent window
		m_pDialog = pdlg; // save "Dlg" pointer


		pdlg->SetWindowTitle(_T("Dynamic Dialog : WindowTitle....."));

		//Add a button control at the given position
		pdlg->AddDlgControl(_T("BUTTON"),			// Type of control OR classname of the control
								_T("Press me!"),		// Caption of control
								STYLE_BUTTON,			// dwStyle of control
								EXSTYLE_BUTTON,		// dwStyleEx of control
								&rect,					// Position of control on dialog in dialog units, default = NULL
								NULL,						// void pointer to variable use for DDX, default = NULL
								IDC_DYN_BUTTON);		// ID of the contol, default = zero

		//Add a group of radio buttons,
		//variable nRadio1 is used for DDX
		pdlg->AddDlgControl(_T("BUTTON"), _T("Radio1Caption 1"), STYLE_RADIO_GROUP, EXSTYLE_RADIO, NULL, (void*)&nRadio1);
		pdlg->AddDlgControl(_T("BUTTON"), _T("Radio1Caption 2"), STYLE_RADIO, EXSTYLE_RADIO);
		pdlg->SetUseSystemButtons(FALSE);
		pdlg->SetUseModeless();
		pdlg->DoModal();
	}
}

void CTestDynDialogDlg::DestroyModelessDialog()
{
	if (m_pDialog != NULL) {
		if (m_pDialog->GetSafeHwnd() != NULL) {
			m_pDialog->DestroyWindow();
		}
		delete m_pDialog;
		m_pDialog = NULL;
	}
}

void CTestDynDialogDlg::OnButton4() 
{
	DestroyModelessDialog();
}


void CTestDynDialogDlg::OnButton5() 
{

	CDynDialogEx dlg(this);
	CRect rect(5,5,250,200);
	dlg.AddDlgControl(_T("MediaPlayer.MediaPlayer.1"), _T(""), WS_VISIBLE | WS_CHILD | WS_TABSTOP | WS_BORDER, 0, &rect);

	dlg.SetWindowTitle(_T("Dynamic Dialog : ALL CONTROLS DYNAMICLY CREATED !!!"));
	dlg.DoModal();
}

void CTestDynDialogDlg::OnButton6() 
{
	CListDynDialogEx dlg(this);
	dlg.DoModal();
}
