#pragma once
#include "afxdialogex.h"


// NewtonDieDaiDlg 对话框

class NewtonDieDaiDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NewtonDieDaiDlg)

public:
	NewtonDieDaiDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~NewtonDieDaiDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NewTonDieDai };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	float m_diedaichuzhi;
};
