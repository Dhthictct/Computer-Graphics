
// DrawFillClipDlg.h : ͷ�ļ�
//
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

#pragma once


// CDrawFillClipDlg �Ի���
class CDrawFillClipDlg : public CDialogEx
{
// ����
public:
	CDrawFillClipDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DRAWFILLCLIP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//��������
	int flag;
	//����ζ���
	int poi[10000][2];
	//����ζ�����
	int num;
	//�߽����
	int vis[40][40];
	// ����
	void DrawPoint(int x, int y, int color);
	afx_msg void OnBnClickedOk();
	// �����Ӧ�¼���־
	afx_msg void OnBnClickedButtonPolygon();
	afx_msg void OnBnClickedButtonSeed();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	// ����
	void DDA(int x1, int y1, int x2, int y2);
	// ����ͨ����ݹ����
	void FloodFill4(int x, int y, int newcolor);
	// �������
	int encode(float x, float y);
	int XL;
	int XR;
	int YB;
	int YT;
	//����������
	int PointCode[1000];
	afx_msg void OnBnClickedButtonWindow();
	afx_msg void OnBnClickedButtonLine();
	//�ü�����
	int cnt;
	int poi_clip[1000][2];
	// ֱ�߲ü�
	void CS_LineClip(float x1, float y1, float x2, float y2);
	afx_msg void OnBnClickedButtonClip();
	// ����ͨ����ݹ����
	void FloodFill8(int x, int y, int newcolor);
};
