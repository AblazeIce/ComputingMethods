#pragma once


// LagrangeDlg 对话框

class LagrangeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LagrangeDlg)

public:
	LagrangeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LagrangeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Lagrange };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	float x0;
	float y0;
	float x1;
	float y1;
	float x2;
	float y2;
	float x;
	int n;
};
