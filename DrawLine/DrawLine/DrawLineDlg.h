
// DrawLineDlg.h : ͷ�ļ�
//

#pragma once


// CDrawLineDlg �Ի���
class CDrawLineDlg : public CDialogEx
{
// ����
public:
	CDrawLineDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void CDrawLineDlg::DrawCircle(int x, int y);

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DRAWLINE_DIALOG };
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
	afx_msg void OnDda();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBresenham();
	afx_msg void OnMiddle();
};
