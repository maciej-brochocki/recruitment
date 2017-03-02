// Okrag.cpp: implementation of the Okrag class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "oke.h"
#include "Okrag.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Okrag::Okrag(int x1, int y1, int x2, int y2) : figura(x1, y1, x2, y2)
{

}

Okrag::~Okrag()
{

}

void Okrag::rysuj(CWnd *okno)
{
	CClientDC dc(okno);
	dc.Arc(m_iX1,m_iY1,m_iX2,m_iY2,(m_iX1+m_iX2)/2,m_iY1,(m_iX1+m_iX2)/2,m_iY1);
	figura::rysuj(okno);
}
