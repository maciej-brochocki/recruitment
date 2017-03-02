// Okrag.h: interface for the Okrag class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OKRAG_H__96682B2D_A82E_48AE_BE7E_23C39D6F7BD7__INCLUDED_)
#define AFX_OKRAG_H__96682B2D_A82E_48AE_BE7E_23C39D6F7BD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "figura.h"

class Okrag : public figura  
{
public:
	void rysuj(CWnd* okno);
	Okrag(int x1, int y1, int x2, int y2);
	virtual ~Okrag();

};

#endif // !defined(AFX_OKRAG_H__96682B2D_A82E_48AE_BE7E_23C39D6F7BD7__INCLUDED_)
