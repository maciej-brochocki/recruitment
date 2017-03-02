// okeDlg.h : header file
//

#include "figura.h"

#if !defined(AFX_OKEDLG_H__FB242918_5BF2_45CD_AC62_29894D3098B9__INCLUDED_)
#define AFX_OKEDLG_H__FB242918_5BF2_45CD_AC62_29894D3098B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COkeDlg dialog

class COkeDlg : public CDialog
{
// Construction
public:
	COkeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COkeDlg)
	enum { IDD = IDD_OKE_DIALOG };
	int		m_iWybor;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COkeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COkeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	figura* m_fFigury;
	int m_iY;
	int m_iX;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OKEDLG_H__FB242918_5BF2_45CD_AC62_29894D3098B9__INCLUDED_)
