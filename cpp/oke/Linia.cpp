// Linia.cpp: implementation of the Linia class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "oke.h"
#include "Linia.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Linia::Linia(int x1, int y1, int x2, int y2) : figura(x1, y1, x2, y2)
{

}

Linia::~Linia()
{

}

void Linia::rysuj(CWnd *okno)
{
	CClientDC dc(okno);
	dc.MoveTo(m_iX1,m_iY1);
	dc.LineTo(m_iX2,m_iY2);
	figura::rysuj(okno);
}
