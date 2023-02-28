#pragma once


// T_Dlg 对话框

class T_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(T_Dlg)

public:
	T_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~T_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_T };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString function;
	float a;
	float b;
	int n;
};
