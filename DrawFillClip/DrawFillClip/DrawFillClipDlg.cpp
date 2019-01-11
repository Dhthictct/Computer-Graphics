
// DrawFillClipDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DrawFillClip.h"
#include "DrawFillClipDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <algorithm>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CDrawFillClipDlg �Ի���



CDrawFillClipDlg::CDrawFillClipDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DRAWFILLCLIP_DIALOG, pParent)
	, flag(0)
	, XL(0)
	, XR(0)
	, YB(0)
	, YT(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrawFillClipDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDrawFillClipDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CDrawFillClipDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_POLYGON, &CDrawFillClipDlg::OnBnClickedButtonPolygon)
	ON_BN_CLICKED(IDC_BUTTON_SEED, &CDrawFillClipDlg::OnBnClickedButtonSeed)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON_WINDOW, &CDrawFillClipDlg::OnBnClickedButtonWindow)
	ON_BN_CLICKED(IDC_BUTTON_LINE, &CDrawFillClipDlg::OnBnClickedButtonLine)
	ON_BN_CLICKED(IDC_BUTTON_CLIP, &CDrawFillClipDlg::OnBnClickedButtonClip)
END_MESSAGE_MAP()


// CDrawFillClipDlg ��Ϣ�������

BOOL CDrawFillClipDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDrawFillClipDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDrawFillClipDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//����ϵ
		CRect rect;//�����ͻ�������
		GetClientRect(&rect);//��ÿͻ�������
		CDC *pDC = GetDC();
		int height = 680;
		int width = 680;
		int i;
		//��X��
		for (i = 0; i <= height; i += 20) {
			pDC->MoveTo(0, i);
			pDC->LineTo(width, i);
		}
		pDC->MoveTo(0, height / 2 + 1);
		pDC->LineTo(width, height / 2 + 1);
		pDC->MoveTo(0, height / 2 - 1);
		pDC->LineTo(width, height / 2 - 1);
		//��Y��
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDrawFillClipDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



// ����
void CDrawFillClipDlg::DrawPoint(int x, int y, int color)
{
	x = 20 * x + 340, y = 340 - y * 20;//ӳ�䵽������
	CDC *pDC = GetDC();
	CBrush Brush;
	Brush.CreateSolidBrush(color);
	pDC->BeginPath();
	pDC->Ellipse(x - 8, y - 8, x + 8, y + 8);
	pDC->EndPath();
	pDC->SelectObject(&Brush);
	pDC->FillPath();
	ReleaseDC(pDC);
}


void CDrawFillClipDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Invalidate();
	UpdateWindow();
	OnPaint();
	memset(vis, 0, sizeof(vis));
	memset(poi, 0, sizeof(poi));
	XL = 30;
	XR = -30;
	YB = 30;
	YT = -30;
	num = 0;
	flag = 0;
	//CDialogEx::OnOK();
}

//���������
void CDrawFillClipDlg::OnBnClickedButtonPolygon()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = 1;
	num = 0;
}

//ѡȡ����
void CDrawFillClipDlg::OnBnClickedButtonSeed()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = 2;
	memset(vis, 0, sizeof(vis));
}

//����flag��Ӧ��ͬ����
void CDrawFillClipDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	POINT p;
	GetCursorPos(&p);
	this->ScreenToClient(&p);
	if (flag == 1) {//��ȡ����ζ���
		if (num == 0) {
			memset(vis, 0, sizeof(vis));
			int x = p.x - 340;
			if (x >= 0) x = (x + 10) / 20;
			else x = (x - 10) / 20;
			int y = 340 - p.y;
			if (y >= 0) y = (y + 10) / 20;
			else y = (y - 10) / 20;
			DrawPoint(x, y, RGB(0, 0, 255));
			poi[num][0] = x;
			poi[num][1] = y;
			++num;
		}
		else {
			int x = p.x - 340;
			if (x >= 0) x = (x + 10) / 20;
			else x = (x - 10) / 20;
			int y = 340 - p.y;
			if (y >= 0) y = (y + 10) / 20;
			else y = (y - 10) / 20;
			poi[num][0] = x;
			poi[num][1] = y;
			++num;
			DDA(poi[num - 2][0], poi[num - 2][1], poi[num - 1][0], poi[num - 1][1]);
		}
	}
	else if (flag == 2) {//���������������
		int color = RGB(255, 0, 0);
		int x = p.x - 340;
		if (x >= 0) x = (x + 10) / 20;
		else x = (x - 10) / 20;
		int y = 340 - p.y;
		if (y >= 0) y = (y + 10) / 20;
		else y = (y - 10) / 20;
		FloodFill4(x, y, color);
		flag = 0;
	}
	else if (flag == 3) {//��ȡ�ü���������
		int color = RGB(0, 0, 255);
		int x = p.x - 340;
		if (x >= 0) x = (x + 10) / 20;
		else x = (x - 10) / 20;
		int y = 340 - p.y;
		if (y >= 0) y = (y + 10) / 20;
		else y = (y - 10) / 20;
		XL = min(XL, x);
		XR = max(XR, x);
		YB = min(YB, y);
		YT = max(YT, y);
		poi_clip[cnt][0] = x;
		poi_clip[cnt][1] = y;
		++cnt;
		if (cnt == 1) {
			DrawPoint(x, y, color);
		}
		else {
			CDC *pDC = GetDC();
			CPen cu;
			cu.CreatePen(PS_SOLID, 3, color);//��ɫ��3���ؿ�
			CPen* oldPen = pDC->SelectObject(&cu);
			pDC->MoveTo(poi_clip[cnt - 2][0] * 20 + 340, 340 - 20 * poi_clip[cnt - 2][1]);
			pDC->LineTo(poi_clip[cnt - 1][0] * 20 + 340, 340 - 20 * poi_clip[cnt - 1][1]);
			DrawPoint(x, y, color);
			ReleaseDC(pDC);
		}
	}
	else if (flag == 4) {//��ȡֱ��
		int color = RGB(255, 0, 0);
		int x = p.x - 340;
		if (x >= 0) x = (x + 10) / 20;
		else x = (x - 10) / 20;
		int y = 340 - p.y;
		if (y >= 0) y = (y + 10) / 20;
		else y = (y - 10) / 20;
		DrawPoint(x, y, color);
		PointCode[num] = encode(x, y);
		poi[num][0] = x;
		poi[num][1] = y;
		++num;
		if (num % 2 == 0) {
			CDC *pDC = GetDC();
			CPen cu;
			cu.CreatePen(PS_SOLID, 3, color);//��ɫ��3���ؿ�
			CPen* oldPen = pDC->SelectObject(&cu);
			pDC->MoveTo(poi[num - 2][0] * 20 + 340, 340 - 20 * poi[num - 2][1]);
			pDC->LineTo(poi[num - 1][0] * 20 + 340, 340 - 20 * poi[num - 1][1]);
			ReleaseDC(pDC);
		}
	}
	//CDialogEx::OnLButtonDown(nFlags, point);
}


// ����
void CDrawFillClipDlg::DDA(int x1, int y1, int x2, int y2)
{
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
	int color = RGB(0, 0, 255);
	if (fabs(k) <= 1) {//k<1��k>-1��ͬ
		int x;
		float y;
		y = y1;
		for (x = x1; x <= x2; ++x) {
			int py = 0;
			if (y >= 0) py = y + 0.5;
			else py = y - 0.5;
			DrawPoint(x, py, color);
			y = y + k;
		}
	}
	else {
		int y;
		float x;
		if (k > 0) {
			x = x1;
			for (y = y1; y <= y2; ++y) {
				int px = 0;
				if (x >= 0) px = x + 0.5;
				else px = x - 0.5;
				DrawPoint(px, y, color);
				x = x + 1 / k;
			}
		}
		else {
			x = x2;
			for (y = y2; y <= y1; ++y) {
				int px = 0;
				if (x >= 0) px = x + 0.5;
				else px = x - 0.5;
				DrawPoint(px, y, color);
				x = x + 1 / k;
			}
		}
	}
}


// ����ͨ����ݹ����
void CDrawFillClipDlg::FloodFill4(int x, int y, int newcolor)
{
	CClientDC dc(this);
	COLORREF color = dc.GetPixel(x * 20 + 340, 340 - 20 * y);
	/*BYTE r = GetRValue(color);
	BYTE g = GetGValue(color);
	BYTE b = GetBValue(color);*/
	COLORREF oldcolor= RGB(0, 0, 255);
	if (color != oldcolor) {
		if (vis[x + 20][y + 20] == 1) return;
		//˯��
		Sleep(30);
		DrawPoint(x, y, newcolor);
		vis[x + 20][y + 20] = 1;
		FloodFill4(x, y + 1, newcolor);
		FloodFill4(x, y - 1,  newcolor);
		FloodFill4(x - 1, y, newcolor);
		FloodFill4(x + 1, y,  newcolor);
	}
}


// �������
int CDrawFillClipDlg::encode(float x, float y)
{
	int c = 0;
	if (x<XL) c |= LEFT;
	if (x>XR) c |= RIGHT;
	if (y<YB) c |= BOTTOM;
	if (y>YT) c |= TOP;
	return c;
}

//��ȡ�ü�����
void CDrawFillClipDlg::OnBnClickedButtonWindow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = 3;
	memset(poi_clip, 0, sizeof(poi_clip));
	cnt = 0;
	XL = 30;
	XR = -30;
	YB = 30;
	YT = -30;
}

//��ȡֱ��
void CDrawFillClipDlg::OnBnClickedButtonLine()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag = 4;
	memset(poi, 0, sizeof(poi));
	num = 0;
}


// ֱ�߲ü�
void CDrawFillClipDlg::CS_LineClip(float x1,float y1,float x2,float y2)
{
	int color = RGB(255, 0, 0);
	CDC *pDC = GetDC();
	CPen cu;
	cu.CreatePen(PS_SOLID, 3, color);
	CPen* oldPen = pDC->SelectObject(&cu);
	
	float x, y;
	int code1, code2, code;
	code1 = encode(x1, y1);
	code2 = encode(x2, y2);
	while (code1 != 0 || code2 != 0) {
		if ((code1&code2) != 0) return;//���˵���ĳһ�߽��������
		//����
		if(code1!=0)code = code1;
		else {
			code = code2;
		}
		if ((LEFT&code) != 0) {
			x = XL;
			y = y1 + (y2 - y1)*(XL - x1) / (x2 - x1);
		}
		else if ((RIGHT&code) != 0) {
			x = XR;
			y = y1 + (y2 - y1)*(XR - x1) / (x2 - x1);
		}
		else if ((BOTTOM&code) != 0) {
			x = x1 + (x2 - x1)*(YB - y1) / (y2 - y1);
			y = YB;
		}
		else if ((TOP&code) != 0) {
			x = x1 + (x2 - x1)*(YT - y1) / (y2 - y1);
			y = YT;
		}
		if (code == code1) {//֮ǰδ����c1��c2
			x1 = x; y1 = y; code1 = encode(x, y);
		}
		else {
			x2 = x; y2 = y; code2 = encode(x, y);
		}
	}
	//�Ե�ȡ��
	int px1, py1, px2, py2;
	if (x1 >= 0) px1 = x1 + 0.5;
	else px1 = x1 - 0.5;
	if (y1 >= 0) py1 = y1 + 0.5;
	else py1 = y1 - 0.5;

	if (x2 >= 0) px2 = x2 + 0.5;
	else px2 = x2 - 0.5;
	if (y2 >= 0) py2 = y2 + 0.5;
	else py2 = y2 - 0.5;
	//������յ�
	DrawPoint(px1, py1, color);
	DrawPoint(px2, py2, color);
	//����յ�����
	pDC->MoveTo(px1 * 20 + 340, 340 - 20 * py1);
	pDC->LineTo(px2 * 20 + 340, 340 - 20 * py2);
	ReleaseDC(pDC);
}


void CDrawFillClipDlg::OnBnClickedButtonClip()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Invalidate();
	UpdateWindow();
	OnPaint();
	//���Ʋ�ɫ��
	CDC *pDC = GetDC();
	CPen cu;
	cu.CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
	CPen* oldPen = pDC->SelectObject(&cu);
	//���Ʋü�����
	pDC->MoveTo(XL * 20 + 340, 340 - 20 * YT);
	pDC->LineTo(XR * 20 + 340, 340 - 20 * YT);
	pDC->MoveTo(XR * 20 + 340, 340 - 20 * YT);
	pDC->LineTo(XR * 20 + 340, 340 - 20 * YB);
	pDC->MoveTo(XR * 20 + 340, 340 - 20 * YB);
	pDC->LineTo(XL * 20 + 340, 340 - 20 * YB);
	pDC->MoveTo(XL * 20 + 340, 340 - 20 * YB);
	pDC->LineTo(XL * 20 + 340, 340 - 20 * YT);
	ReleaseDC(pDC);
	float x1, y1, x2, y2, x, y;
	for (int i = 0; i < num; ++i) {
		if (i & 1) {
			//˯��
			Sleep(200);
			x1 = poi[i - 1][0], y1 = poi[i - 1][1];
			x2 = poi[i][0], y2 = poi[i][1];
			CS_LineClip(x1, y1, x2, y2);
		}
	}
}


// ����ͨ����ݹ����
void CDrawFillClipDlg::FloodFill8(int x, int y, int newcolor)
{
	CClientDC dc(this);
	COLORREF color = dc.GetPixel(x * 20 + 340, 340 - 20 * y);
	COLORREF oldcolor = RGB(0, 0, 255);//�߽���ɫ
	if (color != oldcolor)
	{
		if (vis[x + 20][y + 20] == 1) return;
		Sleep(100);
		DrawPoint(x, y, newcolor);
		vis[x + 20][y + 20] = 1;
		FloodFill8(x, y + 1, newcolor);
		FloodFill8(x, y - 1, newcolor);
		FloodFill8(x - 1, y, newcolor);
		FloodFill8(x + 1, y, newcolor);

		FloodFill8(x - 1, y + 1, newcolor);
		FloodFill8(x + 1, y + 1, newcolor);
		FloodFill8(x - 1, y - 1, newcolor);
		FloodFill8(x + 1, y - 1, newcolor);
	}
}
