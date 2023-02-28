#pragma once


// LU_2Dlg 对话框

class LU_2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(LU_2Dlg)

public:
	LU_2Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LU_2Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LU_2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int n;
	float x11;
	float x12;
	float x13;
	float x14;
	float x21;
	float x22;
	float x23;
	float x24;
	float x31;
	float x32;
	float x33;
	float x34;
};
