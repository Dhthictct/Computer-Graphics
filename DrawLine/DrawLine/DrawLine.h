
// DrawLine.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDrawLineApp: 
// �йش����ʵ�֣������ DrawLine.cpp
//

class CDrawLineApp : public CWinApp
{
public:
	CDrawLineApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDrawLineApp theApp;