// Kwadrat.cpp: implementation of the Kwadrat class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "oke.h"
#include "Kwadrat.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Kwadrat::Kwadrat(int x1, int y1, int x2, int y2) : figura(x1, y1, x2, y2)
{

}

Kwadrat::~Kwadrat()
{

}

void Kwadrat::rysuj(CWnd *okno)
{
	CClientDC dc(okno);
	dc.Rectangle(min(m_iX1,m_iX2),min(m_iY1,m_iY2),min(m_iX1,m_iX2)+max(abs(m_iX1-m_iX2),abs(m_iY1-m_iY2)),min(m_iY1,m_iY2)+max(abs(m_iX1-m_iX2),abs(m_iY1-m_iY2)));
	figura::rysuj(okno);
}
