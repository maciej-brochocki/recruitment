// oke.h : main header file for the OKE application
//

#if !defined(AFX_OKE_H__D5060586_09F5_4DA7_8D92_39BBD48448AC__INCLUDED_)
#define AFX_OKE_H__D5060586_09F5_4DA7_8D92_39BBD48448AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COkeApp:
// See oke.cpp for the implementation of this class
//

class COkeApp : public CWinApp
{
public:
	COkeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COkeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COkeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OKE_H__D5060586_09F5_4DA7_8D92_39BBD48448AC__INCLUDED_)
