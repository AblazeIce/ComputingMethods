#pragma once


// JacobiDieDaiDlg 对话框

class JacobiDieDaiDlg : public CDialogEx
{
	DECLARE_DYNAMIC(JacobiDieDaiDlg)

public:
	JacobiDieDaiDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~JacobiDieDaiDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Jacobi };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	float x0_1;
	float x0_2;
	float x0_3;
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
	int n;
};
