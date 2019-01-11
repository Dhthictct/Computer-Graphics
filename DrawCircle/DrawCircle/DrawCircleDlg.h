
// DrawCircleDlg.h : ͷ�ļ�
//

#pragma once


// CDrawCircleDlg �Ի���
class CDrawCircleDlg : public CDialogEx
{
// ����
public:
	CDrawCircleDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void CDrawCircleDlg::DrawPoint(int x, int y);
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DRAWCIRCLE_DIALOG };
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
	afx_msg void OnBnClickedOk();
	afx_msg void OnCircle();
	afx_msg void OnOval();
	// ���˷�֮һ
	void CirclePoints(int x, int y);
	// ��Բ
	void Circle(int x, int y);
	afx_msg void OnBresenhamcircle();
	// ���ķ�֮һ��Բ
	void OvalPoints(int x, int y);
	// ����Բ
	void Oval(int x, int y);
};
