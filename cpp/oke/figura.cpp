// figura.cpp: implementation of the figura class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "oke.h"
#include "figura.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

figura::figura(int x1, int y1, int x2, int y2) : m_iX1(x1), m_iY1(y1), m_iX2(x2), m_iY2(y2)
{
	m_fNext=NULL;
}

figura::~figura()
{
	if (m_fNext!=NULL)
		delete m_fNext;
}

void figura::dolacz(figura *fig)
{
	if (m_fNext==NULL)
		m_fNext=fig;
	else
		m_fNext->dolacz(fig);
}

void figura::rysuj(CWnd* okno)
{
	if (m_fNext!=NULL)
		m_fNext->rysuj(okno);
}
