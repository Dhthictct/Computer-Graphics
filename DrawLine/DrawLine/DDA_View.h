#pragma once


// DDA_View �Ի���

class DDA_View : public CDialogEx
{
	DECLARE_DYNAMIC(DDA_View)

public:
	DDA_View(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DDA_View();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
