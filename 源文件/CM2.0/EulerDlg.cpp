// EulerDlg.cpp: 实现文件
//

#include "pch.h"
#include "CM2.0.h"
#include "EulerDlg.h"
#include "afxdialogex.h"


// EulerDlg 对话框

IMPLEMENT_DYNAMIC(EulerDlg, CDialogEx)

EulerDlg::EulerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Euler, pParent)
	, function(_T("y-2*x/y"))
	, x0(0)
	, y0(1)
	, n(11)
	, h(0.1)
{

}

EulerDlg::~EulerDlg()
{
}

void EulerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, function);
	DDX_Text(pDX, IDC_EDIT2, x0);
	DDX_Text(pDX, IDC_EDIT10, y0);
	DDX_Text(pDX, IDC_EDIT25, n);
	DDX_Text(pDX, IDC_EDIT11, h);
}


BEGIN_MESSAGE_MAP(EulerDlg, CDialogEx)
END_MESSAGE_MAP()


// EulerDlg 消息处理程序
