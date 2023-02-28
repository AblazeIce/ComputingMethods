// TwoSideDlg.cpp: 实现文件
//

#include "pch.h"
#include "CM2.0.h"
#include "TwoSideDlg.h"
#include "afxdialogex.h"


// TwoSideDlg 对话框

IMPLEMENT_DYNAMIC(TwoSideDlg, CDialogEx)

TwoSideDlg::TwoSideDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TwoSide, pParent)
	, a(1)
	, b(2)
	, function(_T("pow(x,3)-x-1"))
{

}

TwoSideDlg::~TwoSideDlg()
{
}

void TwoSideDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, a);
	DDX_Text(pDX, IDC_EDIT3, b);
	DDX_Text(pDX, IDC_EDIT1, function);
}


BEGIN_MESSAGE_MAP(TwoSideDlg, CDialogEx)
END_MESSAGE_MAP()


// TwoSideDlg 消息处理程序
