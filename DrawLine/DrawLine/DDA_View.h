#pragma once


// DDA_View 对话框

class DDA_View : public CDialogEx
{
	DECLARE_DYNAMIC(DDA_View)

public:
	DDA_View(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DDA_View();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
