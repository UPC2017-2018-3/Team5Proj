// dianmingDlg.h : header file
//

#if !defined(AFX_DIANMINGDLG_H__E750D64C_7CD0_4DD8_BF74_D5609D332DA6__INCLUDED_)
#define AFX_DIANMINGDLG_H__E750D64C_7CD0_4DD8_BF74_D5609D332DA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDianmingDlg dialog

class CDianmingDlg : public CDialog
{
// Construction
public:
	void display();
	BOOL dian;
	void dianming();

	CDianmingDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDianmingDlg)
	enum { IDD = IDD_DIANMING_DIALOG };
	CStatic	m_ming;
	CButton	m_dian;
	CButton	m_stop;
	CString	m_mingzi;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDianmingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDianmingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStop();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int nHeight;
	int nWidth;
	int y;
	int x;
	int x1;
	int y1;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIANMINGDLG_H__E750D64C_7CD0_4DD8_BF74_D5609D332DA6__INCLUDED_)
