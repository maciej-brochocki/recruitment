// Prostokat.cpp: implementation of the Prostokat class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "oke.h"
#include "Prostokat.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Prostokat::Prostokat(int x1, int y1, int x2, int y2) : figura(x1, y1, x2, y2)
{

}

Prostokat::~Prostokat()
{

}

void Prostokat::rysuj(CWnd *okno)
{
	CClientDC dc(okno);
	dc.Rectangle(m_iX1,m_iY1,m_iX2,m_iY2);
	figura::rysuj(okno);
}
