// Gauss_noDlg.cpp: 实现文件
//

#include "pch.h"
#include "CM2.0.h"
#include "Gauss_noDlg.h"
#include "afxdialogex.h"


// Gauss_noDlg 对话框

IMPLEMENT_DYNAMIC(Gauss_noDlg, CDialogEx)

Gauss_noDlg::Gauss_noDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Gauss_no, pParent)
	, n(3)
	, x11(2)
	, x12(4)
	, x13(-2)
	, x14(6)
	, x21(1)
	, x22(-1)
	, x23(5)
	, x24(0)
	, x31(4)
	, x32(1)
	, x33(-2)
	, x34(2)
{

}

Gauss_noDlg::~Gauss_noDlg()
{
}

void Gauss_noDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n);
	DDX_Text(pDX, IDC_EDIT2, x11);
	DDX_Text(pDX, IDC_EDIT3, x12);
	DDX_Text(pDX, IDC_EDIT10, x13);
	DDX_Text(pDX, IDC_EDIT11, x14);
	DDX_Text(pDX, IDC_EDIT6, x21);
	DDX_Text(pDX, IDC_EDIT7, x22);
	DDX_Text(pDX, IDC_EDIT12, x23);
	DDX_Text(pDX, IDC_EDIT13, x24);
	DDX_Text(pDX, IDC_EDIT9, x31);
	DDX_Text(pDX, IDC_EDIT14, x32);
	DDX_Text(pDX, IDC_EDIT15, x33);
	DDX_Text(pDX, IDC_EDIT16, x34);
}


BEGIN_MESSAGE_MAP(Gauss_noDlg, CDialogEx)
END_MESSAGE_MAP()


// Gauss_noDlg 消息处理程序
