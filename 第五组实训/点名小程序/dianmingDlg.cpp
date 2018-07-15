// dianmingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dianming.h"
#include "dianmingDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CDianmingDlg dialog

CDianmingDlg::CDianmingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDianmingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDianmingDlg)
	m_mingzi = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDianmingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDianmingDlg)
	DDX_Control(pDX, IDC_MINGZI, m_ming);
	DDX_Control(pDX, IDOK, m_dian);
	DDX_Control(pDX, IDC_STOP, m_stop);
	DDX_Text(pDX, IDC_MINGZI, m_mingzi);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDianmingDlg, CDialog)
	//{{AFX_MSG_MAP(CDianmingDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDianmingDlg message handlers

BOOL CDianmingDlg::OnInitDialog()
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
	m_stop.ShowWindow(FALSE);
    // CStatic m_ming;
	CFont *font;
    font=new CFont;
	font->CreateFont(80,0,0,0,FW_NORMAL,FALSE,FALSE,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,_T("楷体_GB2312"));
	GetDlgItem(IDC_MINGZI)->SetFont(font);
    CRect dlg;
CRect desk;
GetWindowRect(dlg);
GetDesktopWindow()->GetWindowRect(desk);
MoveWindow((desk.Width()-dlg.Width())/2,(desk.Height()-dlg.Height())/2,0,0);
nWidth=dlg.Width();
nHeight=dlg.Height();
x=5;
y=2;
x1=2;
y1=2;
SetTimer(2,10,NULL);

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDianmingDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDianmingDlg::OnPaint() 
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
HCURSOR CDianmingDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDianmingDlg::OnOK() 
{
	// TODO: Add extra validation here
	m_stop.ShowWindow(TRUE);
	m_dian.ShowWindow(FALSE);
	FILE *fp;
	int j=0;
	if((fp=fopen("student.txt","r"))==NULL)
	{
		MessageBox("打开文件出错！"," 警告",MB_OK|MB_ICONSTOP);
		m_stop.ShowWindow(FALSE);
		m_dian.ShowWindow(TRUE);
		return;
	}
	else
	{
	dianming();
	SetTimer(1,50,NULL);
	dian=TRUE;
	}
	
//	CDialog::OnOK();
}

void CDianmingDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==1)
	{
		if(dian=TRUE)
			display();
	}
	if(nIDEvent==2)
	{
		CRect dlg;
       CRect desk;
       GetWindowRect(dlg);
       GetDesktopWindow()->GetWindowRect(desk);
		 MoveWindow((+desk.Width()-dlg.Width())/2,(+desk.Height()-dlg.Height())/2,x+dlg.Width(),y+dlg.Height());
	   if(dlg.Width()>=nWidth)
		   x=0;
	   if(dlg.Height()>=nHeight)
		   y=0;
	   if(dlg.Width()>=nWidth&&dlg.Height()>=nHeight)
		   KillTimer(4);
	   }
	CDialog::OnTimer(nIDEvent);
}
int i=0;
char stu[1000][30];
void CDianmingDlg::dianming()
{
	FILE *fp;
	char ch;
	int j=0;
	fp=fopen("student.txt","r");
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		stu[i][j]=ch;
		j++;
		if(ch=='\n')
		{
		stu[i][j]='\0';
		i++;
		j=0;
		}
		ch=fgetc(fp);
	}


}

void CDianmingDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	dian=FALSE;
	KillTimer(1);
	m_stop.ShowWindow(FALSE);
	m_dian.ShowWindow(TRUE);


}

void CDianmingDlg::display()
{
	static int k=i;
		CString str;
	str.Format("%s",stu[i]);
	CStatic* st=(CStatic*)GetDlgItem(IDC_MINGZI);
	st->SetWindowText(str);
		if(i<=0)
		{
			i=k;
		}
		else
		{
			i--;
		}


}

HBRUSH CDianmingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor==CTLCOLOR_STATIC)
	{
		HBRUSH b=CreateSolidBrush(RGB(0,0,0));
		pDC->SetTextColor(RGB(0,255,0));
	    pDC->SetBkColor(RGB(0,0,0));
		return b;
	}
	if(nCtlColor==CTLCOLOR_DLG)
	{
		HBRUSH B=CreateSolidBrush(RGB(6,219,239));
		return B;
	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
