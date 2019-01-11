
// DrawFillClipDlg.h : 头文件
//
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

#pragma once


// CDrawFillClipDlg 对话框
class CDrawFillClipDlg : public CDialogEx
{
// 构造
public:
	CDrawFillClipDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DRAWFILLCLIP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//操作种类
	int flag;
	//多边形顶点
	int poi[10000][2];
	//多边形顶点数
	int num;
	//边界点标记
	int vis[40][40];
	// 画点
	void DrawPoint(int x, int y, int color);
	afx_msg void OnBnClickedOk();
	// 鼠标响应事件标志
	afx_msg void OnBnClickedButtonPolygon();
	afx_msg void OnBnClickedButtonSeed();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	// 画线
	void DDA(int x1, int y1, int x2, int y2);
	// 四连通区域递归填充
	void FloodFill4(int x, int y, int newcolor);
	// 区域编码
	int encode(float x, float y);
	int XL;
	int XR;
	int YB;
	int YT;
	//点的区域编码
	int PointCode[1000];
	afx_msg void OnBnClickedButtonWindow();
	afx_msg void OnBnClickedButtonLine();
	//裁剪窗口
	int cnt;
	int poi_clip[1000][2];
	// 直线裁剪
	void CS_LineClip(float x1, float y1, float x2, float y2);
	afx_msg void OnBnClickedButtonClip();
	// 八连通区域递归填充
	void FloodFill8(int x, int y, int newcolor);
};
