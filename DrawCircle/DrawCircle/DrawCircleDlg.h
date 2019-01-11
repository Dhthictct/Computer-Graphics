
// DrawCircleDlg.h : 头文件
//

#pragma once


// CDrawCircleDlg 对话框
class CDrawCircleDlg : public CDialogEx
{
// 构造
public:
	CDrawCircleDlg(CWnd* pParent = NULL);	// 标准构造函数
	void CDrawCircleDlg::DrawPoint(int x, int y);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DRAWCIRCLE_DIALOG };
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
	afx_msg void OnBnClickedOk();
	afx_msg void OnCircle();
	afx_msg void OnOval();
	// 画八分之一
	void CirclePoints(int x, int y);
	// 画圆
	void Circle(int x, int y);
	afx_msg void OnBresenhamcircle();
	// 画四分之一椭圆
	void OvalPoints(int x, int y);
	// 画椭圆
	void Oval(int x, int y);
};
