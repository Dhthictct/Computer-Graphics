
// DrawFillClip.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDrawFillClipApp: 
// �йش����ʵ�֣������ DrawFillClip.cpp
//

class CDrawFillClipApp : public CWinApp
{
public:
	CDrawFillClipApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDrawFillClipApp theApp;