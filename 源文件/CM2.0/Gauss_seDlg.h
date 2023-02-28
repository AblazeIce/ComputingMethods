#pragma once


// Gauss_seDlg 对话框

class Gauss_seDlg : public CDialogEx
{
	DECLARE_DYNAMIC(Gauss_seDlg)

public:
	Gauss_seDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Gauss_seDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Gauss_se };
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
	float x15;
	float x21;
	float x22;
	float x23;
	float x24;
	float x25;

	float x31;
	float x32;
	float x33;
	float x34;
	float x35;

	float x41;
	float x42;
	float x43;
	float x44;
	float x45;
};
