#pragma once


// Gauss_noDlg 对话框

class Gauss_noDlg : public CDialogEx
{
	DECLARE_DYNAMIC(Gauss_noDlg)

public:
	Gauss_noDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Gauss_noDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Gauss_no };
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
