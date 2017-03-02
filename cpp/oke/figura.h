// figura.h: interface for the figura class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIGURA_H__C5E3A844_E3E2_4B76_B7D4_0AEB97C600B3__INCLUDED_)
#define AFX_FIGURA_H__C5E3A844_E3E2_4B76_B7D4_0AEB97C600B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class figura  
{
public:
	virtual void rysuj(CWnd* okno);
	void dolacz(figura* fig);
	figura(int x1, int y1, int x2, int y2);
	virtual ~figura();

protected:
	figura* m_fNext;
	int m_iY2;
	int m_iX2;
	int m_iY1;
	int m_iX1;
};

#endif // !defined(AFX_FIGURA_H__C5E3A844_E3E2_4B76_B7D4_0AEB97C600B3__INCLUDED_)
