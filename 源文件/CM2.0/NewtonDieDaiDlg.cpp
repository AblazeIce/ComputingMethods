// NewtonDieDaiDlg.cpp: 实现文件
//

#include "pch.h"
#include "CM2.0.h"
#include "afxdialogex.h"
#include "NewtonDieDaiDlg.h"


// NewtonDieDaiDlg 对话框

IMPLEMENT_DYNAMIC(NewtonDieDaiDlg, CDialogEx)

NewtonDieDaiDlg::NewtonDieDaiDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NewTonDieDai, pParent)
	, m_diedaichuzhi(1)
{

}

NewtonDieDaiDlg::~NewtonDieDaiDlg()
{
}

void NewtonDieDaiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_diedaichuzhi);
}


BEGIN_MESSAGE_MAP(NewtonDieDaiDlg, CDialogEx)
END_MESSAGE_MAP()


// NewtonDieDaiDlg 消息处理程序
