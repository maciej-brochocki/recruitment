// Linia.h: interface for the Linia class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINIA_H__22A19C43_BDC9_47CB_9F56_F51967B349BF__INCLUDED_)
#define AFX_LINIA_H__22A19C43_BDC9_47CB_9F56_F51967B349BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "figura.h"

class Linia : public figura  
{
public:
	void rysuj(CWnd* okno);
	Linia(int x1, int y1, int x2, int y2);
	virtual ~Linia();

};

#endif // !defined(AFX_LINIA_H__22A19C43_BDC9_47CB_9F56_F51967B349BF__INCLUDED_)
