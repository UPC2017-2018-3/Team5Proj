// dianming.h : main header file for the DIANMING application
//

#if !defined(AFX_DIANMING_H__DD6F28D7_F00B_4B2E_A6A1_6402263A80B3__INCLUDED_)
#define AFX_DIANMING_H__DD6F28D7_F00B_4B2E_A6A1_6402263A80B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDianmingApp:
// See dianming.cpp for the implementation of this class
//

class CDianmingApp : public CWinApp
{
public:
	CDianmingApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDianmingApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDianmingApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIANMING_H__DD6F28D7_F00B_4B2E_A6A1_6402263A80B3__INCLUDED_)
