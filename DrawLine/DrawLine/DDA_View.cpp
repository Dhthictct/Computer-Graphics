// DDA_View.cpp : 实现文件
//

#include "stdafx.h"
#include "DrawLine.h"
#include "DDA_View.h"
#include "afxdialogex.h"


// DDA_View 对话框

IMPLEMENT_DYNAMIC(DDA_View, CDialogEx)

DDA_View::DDA_View(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

DDA_View::~DDA_View()
{
}

void DDA_View::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DDA_View, CDialogEx)
END_MESSAGE_MAP()


// DDA_View 消息处理程序
