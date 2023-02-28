#pragma once


// SimpleDieDaiDlg 对话框

class SimpleDieDaiDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SimpleDieDaiDlg)

public:
	SimpleDieDaiDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SimpleDieDaiDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SimpleDieDai };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString function;
	float x0;
};
