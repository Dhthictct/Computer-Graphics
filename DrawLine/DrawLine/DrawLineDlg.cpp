
// DrawLineDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DrawLine.h"
#include "DrawLineDlg.h"
#include "afxdialogex.h"

#include<iostream>
#include<algorithm>
using namespace std;

#include "DDA_View.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
//public:
	//afx_msg void OnDda();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	//ON_COMMAND(ID_DDA, &CAboutDlg::OnDda)
END_MESSAGE_MAP()


// CDrawLineDlg 对话框



CDrawLineDlg::CDrawLineDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DRAWLINE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrawLineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDrawLineDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_DDA, &CDrawLineDlg::OnDda)
	ON_BN_CLICKED(IDOK, &CDrawLineDlg::OnBnClickedOk)
	ON_COMMAND(ID_Bresenham, &CDrawLineDlg::OnBresenham)
	ON_COMMAND(ID_Middle, &CDrawLineDlg::OnMiddle)
END_MESSAGE_MAP()


// CDrawLineDlg 消息处理程序

BOOL CDrawLineDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDrawLineDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDrawLineDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//坐标系
		CRect rect;//声明客户区矩形
		GetClientRect(&rect);//获得客户区坐标
		CDC *pDC = GetDC();
		int height = 680;
		int width = 680;
		int i;
		//画X轴
		for (i = 0; i <= height; i+=20) {
			pDC->MoveTo(0, i);
			pDC->LineTo(width, i);
		}
		pDC->MoveTo(0, height/2+1);
		pDC->LineTo(width, height / 2+1);
		pDC->MoveTo(0, height / 2 - 1);
		pDC->LineTo(width, height / 2 - 1);
		//画Y轴
		for (i = 0; i <= width; i += 20) {
			pDC->MoveTo(i, 0);
			pDC->LineTo(i, height);
		}
		pDC->MoveTo(width/2+1, 0);
		pDC->LineTo(width/2+1, height);
		pDC->MoveTo(width / 2 - 1, 0);
		pDC->LineTo(width / 2 - 1, height);

		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDrawLineDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDrawLineDlg::DrawCircle(int x, int y) {//画实心圆
	CDC *pDC = GetDC();
	CBrush Brush;
	Brush.CreateSolidBrush(RGB(255, 0, 0));
	pDC->BeginPath();
	pDC->Ellipse(x - 8, y - 8, x + 8, y + 8);
	pDC->EndPath();
	pDC->SelectObject(&Brush);
	pDC->FillPath();
	ReleaseDC(pDC);
}

void CDrawLineDlg::OnDda()
{
	// TODO: 在此添加命令处理程序代码
	int x1, y1, x2, y2,color;
	color = RGB(255, 0, 0);
	x1 = GetDlgItemInt(IDC_EDIT_X1);
	y1 = GetDlgItemInt(IDC_EDIT_Y1);
	x2 = GetDlgItemInt(IDC_EDIT_X2);
	y2 = GetDlgItemInt(IDC_EDIT_Y2);

	if (x1 > x2) {
		swap(x1, x2);
		swap(y1, y2);
	}
	else if (x1 == x2) {
		if (y1 > y2) {
			swap(y1, y2);
		}
	}
	float dx, dy, k, y;
	dx = x2 - x1; dy = y2 - y1;
	k = dy / dx;
	
	if (fabs(k) <= 1) {//k<1和k>-1相同
		int x;
		float y;
		y = y1;
		for (x = x1; x <= x2; ++x) {
			//pdc->SetPixel(x, int(y + 0.5), color);
			int px = 20 * x + 340, py;//映射到坐标系上
			if (y >= 0) py = 340 - int(y + 0.5)*(20);
			else py = 340 - int(y - 0.5)*(20);
			DrawCircle(px, py);
			y = y + k;
		}
	}
	else {
		int y;
		float x;
		if (k > 0) {
			x = x1;
			for (y = y1; y <= y2; ++y) {
				//pdc->SetPixel(int(x+0.5), y, color);
				int py=340 - 20 * y, px;//映射到坐标系上
				if (x >= 0) px = int(x + 0.5)*(20) + 340;
				else px = int(x - 0.5)*(20) + 340;
				DrawCircle(px, py);
				x = x + 1 / k;
			}
		}
		else {
			x = x2;
			for (y = y2; y <= y1; ++y) {
				//pdc->SetPixel(int(x+0.5), y, color);
				int py = 340 - 20 * y, px;//映射到坐标系上
				if (x >= 0) px = int(x + 0.5)*(20) + 340;
				else px = int(x - 0.5)*(20) + 340;
				DrawCircle(px, py);
				x = x + 1 / k;
			}
		}
	}
}


void CDrawLineDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	Invalidate();
	UpdateWindow();
	OnPaint();
}


void CDrawLineDlg::OnBresenham()
{
	// TODO: 在此添加命令处理程序代码
	int x1, y1, x2, y2, color;
	color = RGB(255, 0, 0);
	x1 = GetDlgItemInt(IDC_EDIT_X1);
	y1 = GetDlgItemInt(IDC_EDIT_Y1);
	x2 = GetDlgItemInt(IDC_EDIT_X2);
	y2 = GetDlgItemInt(IDC_EDIT_Y2);

	if (x1 >= x2) {
		swap(x1, x2);
		swap(y1, y2);
	}
	else if (x1 == x2) {
		if (y1 > y2) {
			swap(y1, y2);
		}
	}
	int x, y, dx, dy;
	float k, e;

	dx = x2 - x1, dy = y2 - y1, k = dy*1.0 / dx;
	x = x1, y = y1;
	if (fabs(k) <= 1) {
		if (k > 0) {
			e = -dx;
			for (int i = 0; i <= dx; i++) {
				//pdc->SetPixel(x, y, color);
				int px = 20 * x + 340, py = 340 - int(y)*(20);//映射到坐标系上
				DrawCircle(px, py);
				x++;
				e = e + 2 * dy;
				if (e >= 0) {
					y++;
					e = e - 2 * dx;
				}
			}
		}
		else {
			e = -dx;
			for (int i = 0; i <= dx; i++) {
				//pdc->SetPixel(x, y, color);
				int px = 20 * x + 340, py = 340 - int(y)*(20);//映射到坐标系上
				DrawCircle(px, py);
				x++;
				/*e = e + 2 * dy;
				if (e < 0) {
					y--;
					e = e + 2 * dx;
				}*/
				e = e - 2 * dy;
				if (e >= 0) {
				y--;
				e = e - 2 * dx;
				}
			}
		}
	}
	else {
		if (k > 0) {
			e = -dy;
			for (int i = 0; i <= dy; i++) {
				//pdc->SetPixel(x, y, color);
				int py = 340 - 20 * y, px = int(x)*(20) + 340;//映射到坐标系上
				DrawCircle(px, py);
				y++;
				e = e + 2 * dx;
				if (e >= 0) {
					x++;
					e = e - 2 * dy;
				}
			}
		}
		else {
			e = dy;
			for (int i = 0; i <= -dy; i++) {
				//pdc->SetPixel(x, y, color);
				int py = 340 - 20 * y, px = int(x)*(20) + 340;//映射到坐标系上
				DrawCircle(px, py);
				y--;//y1>y2 递减
				e = e + 2 * dx;
				if (e >= 0) {
					x++;
					e = e + 2 * dy;
				}
			}
		}
	}
}


void CDrawLineDlg::OnMiddle()
{
	// TODO: 在此添加命令处理程序代码
	int x1, y1, x2, y2, color;
	color = RGB(255, 0, 0);
	x1 = GetDlgItemInt(IDC_EDIT_X1);
	y1 = GetDlgItemInt(IDC_EDIT_Y1);
	x2 = GetDlgItemInt(IDC_EDIT_X2);
	y2 = GetDlgItemInt(IDC_EDIT_Y2);

	if (x1 >= x2) {
		swap(x1, x2);
		swap(y1, y2);
	}
	else if (x1 == x2) {
		if (y1 > y2) {
			swap(y1, y2);
		}
	}
	float k = (y2 - y1)*1.0 / (x2 - x1);
	int a, b, d1, d2, d, x, y;
	a = y1 - y2, b = x2 - x1; 
	x = x1, y = y1;
	int py = 340 - 20 * y, px = x * 20 + 340;//映射到坐标系上
	//c->SetPixel(x, y, color);
	DrawCircle(px, py);
	if (fabs(k) <= 1) {
		if (k > 0) {
			d = 2 * a + b;
			d1 = 2 * a;
			d2 = 2 * (a + b);
			while (x < x2) {
				if (d < 0) {
					x++, y++, d += d2;
				}
				else {
					x++, d += d1;
				}
				//c->SetPixel(x, y, color);
				py = 340 - 20 * y, px = x * 20 + 340;//映射到坐标系上
				DrawCircle(px, py);
			}
		}
		else {
			d = 2 * a - b;
			d1 = 2 * a;
			d2 = 2 * (a - b);
			while (x < x2) {
				if (d < 0) {
					x++, d += d1;
				}
				else {
					x++, y--, d += d2;
				}
				//c->SetPixel(x, y, color);
				py = 340 - 20 * y, px = x * 20 + 340;//映射到坐标系上
				DrawCircle(px, py);
			}
		}
	}
	else {
		if (k > 0) {
			d = a + 2 * b;
			d1 = 2 * b;
			d2 = 2 * (a + b);
			while (y < y2) {
				if (d < 0) {
					y++, d += d1;
				}
				else {
					x++, y++, d += d2;
				}
				//c->SetPixel(x, y, color);
				py = 340 - 20 * y, px = x * 20 + 340;//映射到坐标系上
				DrawCircle(px, py);
			}
		}
		else {
			d = a - 2 * b;
			d1 = -2 * b;
			d2 = 2 * (a - b);
			while (y > y2) {
				if (d < 0) {
					x++, y--, d += d2;
				}
				else {
					y--, d += d1;
				}
				//c->SetPixel(x, y, color);
				py = 340 - 20 * y, px = x * 20 + 340;//映射到坐标系上
				DrawCircle(px, py);
			}
		}
	}
	
}
