// Prostokat.h: interface for the Prostokat class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROSTOKAT_H__8BFC51D3_A4C6_402A_A653_A4124400AB08__INCLUDED_)
#define AFX_PROSTOKAT_H__8BFC51D3_A4C6_402A_A653_A4124400AB08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "figura.h"

class Prostokat : public figura  
{
public:
	void rysuj(CWnd* okno);
	Prostokat(int x1, int y1, int x2, int y2);
	virtual ~Prostokat();

};

#endif // !defined(AFX_PROSTOKAT_H__8BFC51D3_A4C6_402A_A653_A4124400AB08__INCLUDED_)
