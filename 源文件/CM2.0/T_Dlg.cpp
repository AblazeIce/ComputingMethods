// T_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "CM2.0.h"
#include "T_Dlg.h"
#include "afxdialogex.h"


// T_Dlg 对话框

IMPLEMENT_DYNAMIC(T_Dlg, CDialogEx)

T_Dlg::T_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_T, pParent)
	, function(_T("1/(1+x)"))
	, a(0)
	, b(1)
	, n(10)
{

}

T_Dlg::~T_Dlg()
{
}

void T_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, function);
	DDX_Text(pDX, IDC_EDIT2, a);
	DDX_Text(pDX, IDC_EDIT10, b);
	DDX_Text(pDX, IDC_EDIT25, n);
}


BEGIN_MESSAGE_MAP(T_Dlg, CDialogEx)
END_MESSAGE_MAP()


// T_Dlg 消息处理程序
