#pragma once


// EulerDlg 对话框

class EulerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EulerDlg)

public:
	EulerDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~EulerDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Euler };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString function;
	float x0;
	float y0;
	int n;
	float h;
};
