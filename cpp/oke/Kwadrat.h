// Kwadrat.h: interface for the Kwadrat class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_KWADRAT_H__2BBFA872_12F0_4640_881E_0C022C8B0122__INCLUDED_)
#define AFX_KWADRAT_H__2BBFA872_12F0_4640_881E_0C022C8B0122__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "figura.h"

class Kwadrat : public figura  
{
public:
	void rysuj(CWnd* okno);
	Kwadrat(int x1, int y1, int x2, int y2);
	virtual ~Kwadrat();

};

#endif // !defined(AFX_KWADRAT_H__2BBFA872_12F0_4640_881E_0C022C8B0122__INCLUDED_)
