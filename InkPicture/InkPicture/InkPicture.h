
// InkPicture.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CInkPictureApp: 
// �йش����ʵ�֣������ InkPicture.cpp
//

class CInkPictureApp : public CWinApp
{
public:
	CInkPictureApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CInkPictureApp theApp;