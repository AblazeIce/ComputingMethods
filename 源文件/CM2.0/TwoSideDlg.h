#pragma once


// TwoSideDlg 对话框

class TwoSideDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TwoSideDlg)

public:
	TwoSideDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TwoSideDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TwoSide };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	float a;
	float b;
	CString function;
};
