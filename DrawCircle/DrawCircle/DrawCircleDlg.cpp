
// DrawCircleDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DrawCircle.h"
#include "DrawCircleDlg.h"
#include "afxdialogex.h"

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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDrawCircleDlg 对话框



CDrawCircleDlg::CDrawCircleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DRAWCIRCLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrawCircleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDrawCircleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CDrawCircleDlg::OnBnClickedOk)
	ON_COMMAND(ID_CIRCLE, &CDrawCircleDlg::OnCircle)
	ON_COMMAND(ID_OVAL, &CDrawCircleDlg::OnOval)
	ON_COMMAND(BresenhamCircle, &CDrawCircleDlg::OnBresenhamcircle)
END_MESSAGE_MAP()


// CDrawCircleDlg 消息处理程序

BOOL CDrawCircleDlg::OnInitDialog()
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

void CDrawCircleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDrawCircleDlg::OnPaint()
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
		for (i = 0; i <= height; i += 20) {
			pDC->MoveTo(0, i);
			pDC->LineTo(width, i);
		}
		pDC->MoveTo(0, height / 2 + 1);
		pDC->LineTo(width, height / 2 + 1);
		pDC->MoveTo(0, height / 2 - 1);
		pDC->LineTo(width, height / 2 - 1);
		//画Y轴
		for (i = 0; i <= width; i += 20) {
			pDC->MoveTo(i, 0);
			pDC->LineTo(i, height);
		}
		pDC->MoveTo(width / 2 + 1, 0);
		pDC->LineTo(width / 2 + 1, height);
		pDC->MoveTo(width / 2 - 1, 0);
		pDC->LineTo(width / 2 - 1, height);
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDrawCircleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDrawCircleDlg::DrawPoint(int x, int y) {//画实心圆
	x = 20 * x + 340, y = 340 - y * 20;//映射到坐标上
	CDC *pDC = GetDC();
	CBrush Brush;
	int color = RGB(255, 0, 0);
	Brush.CreateSolidBrush(color);
	pDC->BeginPath();
	pDC->Ellipse(x - 8, y - 8, x + 8, y + 8);
	pDC->EndPath();
	pDC->SelectObject(&Brush);
	pDC->FillPath();
	ReleaseDC(pDC);
}

void CDrawCircleDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	Invalidate();
	UpdateWindow();
	OnPaint();
	//CDialogEx::OnOK();
}


void CDrawCircleDlg::OnCircle()
{
	// TODO: 在此添加命令处理程序代码
	int x, y, r;
	r= GetDlgItemInt(IDC_EDIT_A);
	//float d;
	int d;
	x = 0, y = r;
	//d = 1.25 - r;
	d = 1 - r;
	CirclePoints(x, y);
	while (x < y) {
		if (d < 0)
			d += 2 * x + 3;
		else {
			d += 2 * (x - y) + 5; 
			y--;
		}
		x++;
		CirclePoints(x, y);
	}
}

void CDrawCircleDlg::OnBresenhamcircle()
{
	// TODO: 在此添加命令处理程序代码
	int r = GetDlgItemInt(IDC_EDIT_A);
	int x, y, delta, delta1, delta2, direction;
	x = 0; y = r;
	delta = 2 * (1 - r);  //△D的初始值
	int Limit = 0;
	while (y >= Limit)
	{
		CirclePoints(x, y);
		if (delta <0) {
			delta1 = 2 * (delta + y) - 1;//△HD
			if (delta1 < 0) direction = 1;//取H点
			else direction = 2; //取D点
		}else if (delta>0) {
			delta2 = 2 * (delta - x) - 1;//△DV
			if (delta2 <0) direction = 2;//取D点
			else direction = 3; //取V点
		}else
			direction = 2;//取D点
		switch (direction) {
		case 1:   x++;
			delta += 2 * x + 1;
			break;
		case 2:   x++;
			y--;
			delta += 2 * (x - y + 1);
			break;
		case 3:   y--;
			delta += (-2 * y + 1);
			break;
		}
	}
}

void CDrawCircleDlg::OnOval()
{
	// TODO: 在此添加命令处理程序代码
	int a, b;
	a = GetDlgItemInt(IDC_EDIT_A);
	b = GetDlgItemInt(IDC_EDIT_B);
	/*int x, y, taa, t2aa, t4aa, tbb, t2bb, t4bb, t2abb, t2bbx, tx;
	float d1, d2;
	x = (a + 0.5);
	y = 0;
	taa = a*a;
	t2aa = 2*taa;
	t4aa = 2 * t2aa; 

	tbb = b*b;
	t2bb = 2 * tbb;
	t4bb = 2 * t2bb;

	t2abb = a*t2bb;
	t2bbx = t2bb*x;
	tx = x;
	d1 = t2bbx*(x - 1) + tbb*1.0 / 2 + t2aa*(1 - tbb);
	
	while (t2bb*tx > t2aa*y) {//区域一
		OvalPoints(x, y);
		if (d1 < 0) {
			y = y + 1;
			d1 = d1 + t4aa*y + t2aa;
			tx = x - 1;
		}
		else {
			x = x - 1;
			y = y + 1;
			d1 = d1 - t4bb*x + t4aa*y + t2aa;
			tx = x;
		}
	}
	d2 = t2bb*(x*x + 1) - t4bb*x + t2aa*(y*y - tbb) + taa*1.0 / 2;
	while (x >= 0) {
		OvalPoints(x, y);
		if (d2 < 0) {
			x = x - 1;
			y = y + 1;
			d2 = d2 + t4aa*y - t4bb*x + t2bb;
		}
		else {
			x = x - 1;
			d2 = d2 - t4bb*x + t2bb;
		}
	}*/
	int x, y, a2, b2;
	a2 = a*a;
	b2 = b*b;
	//float d1, d2;
	//d1 = b2 + a2*(-b + 0.25);
	int d1, d2;
	d1 = 4*b2 + a2*(-4*b + 1);
	x = 0;
	y = (b + 0.5);
	//while (b2*(x + 1) <= a2*(y - 0.5)) {
	while (b2*(x + 1)*2 <= a2*(2*y - 1)) {
		OvalPoints(x, y);
		if (d1 < 0) {
			d1 += 4*b2*(2 * x + 3);
			x++;
		}
		else {
			d1 += 4*b2*(2 * x + 3) + 4*a2*(-2 * y + 2);
			y--;
			x++;
		}
	}
	//d2 = b2*(x + 0.5)*(x + 0.5) + a2*(y - 1)*(y - 1) - a2*b2;
	d2 = b2*(4 * x*x + 4 * x + 1) + 4 * a2*(y - 1)*(y - 1) - 4 * a2*b2;
	while(y >= 0){
		OvalPoints(x, y);
		if (d2 > 0) {
			d2 += 4*a2*(-2 * y + 3);
			y--;
		}
		else {
			d2 += 4*b2*(2 * x + 2) + 4*a2*(-2 * y + 3);
			x++;
			y--;
		}
	}
}


// 八分之一对称画圆
void CDrawCircleDlg::CirclePoints(int x, int y)
{
	Circle(x, y); Circle(y, x);
	Circle(-x, y); Circle(y, -x);
	Circle(x, -y); Circle(-y, x);
	Circle(-x, -y); Circle(-y, -x);
}


// 画圆
void CDrawCircleDlg::Circle(int x, int y)
{
	int dx, dy;
	dx = GetDlgItemInt(IDC_EDIT_CENTERX);
	dy = GetDlgItemInt(IDC_EDIT_CENTERY);
	x += dx, y += dy;//加上偏移
	DrawPoint(x, y);
}

//四分之一对称画椭圆
void CDrawCircleDlg::OvalPoints(int x, int y)
{
	Oval(x, y);Oval(x, -y);
	Oval(-x, y);Oval(-x, -y);
}

// 画椭圆
void CDrawCircleDlg::Oval(int x, int y)
{
	int dx, dy;
	dx = GetDlgItemInt(IDC_EDIT_CENTERX);
	dy = GetDlgItemInt(IDC_EDIT_CENTERY);
	x += dx, y += dy;//加上偏移
	DrawPoint(x, y);
}
