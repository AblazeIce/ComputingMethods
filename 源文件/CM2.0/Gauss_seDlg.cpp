// Gauss_seDlg.cpp: 实现文件
//

#include "pch.h"
#include "CM2.0.h"
#include "Gauss_seDlg.h"
#include "afxdialogex.h"


// Gauss_seDlg 对话框

IMPLEMENT_DYNAMIC(Gauss_seDlg, CDialogEx)

Gauss_seDlg::Gauss_seDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Gauss_se, pParent)
	, n(4)
	, x11(0.4096)
	, x12(0.1234)
	, x13(0.3678)
	, x14(0.2943)
	, x15(0.4043)

	, x21(0.2246)
	, x22(0.3872)
	, x23(0.4015)
	, x24(0.1129)
	, x25(0.155)

	, x31(0.3645)
	, x32(0.192)
	, x33(0.3781)
	, x34(0.0643)
	, x35(0.424)

	, x41(0.1784)
	, x42(0.4002)
	, x43(0.2786)
	, x44(0.3927)
	, x45(-0.2557)
{

}

Gauss_seDlg::~Gauss_seDlg()
{
}

void Gauss_seDlg::DoDataExchange(CDataExchange* pDX)
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
	DDX_Text(pDX, IDC_EDIT17, x14);
	DDX_Text(pDX, IDC_EDIT11, x15);
	DDX_Text(pDX, IDC_EDIT18, x25);
	DDX_Text(pDX, IDC_EDIT19, x35);
	DDX_Text(pDX, IDC_EDIT20, x41);
	DDX_Text(pDX, IDC_EDIT21, x42);
	DDX_Text(pDX, IDC_EDIT22, x43);
	DDX_Text(pDX, IDC_EDIT23, x44);
	DDX_Text(pDX, IDC_EDIT24, x45);
}


BEGIN_MESSAGE_MAP(Gauss_seDlg, CDialogEx)
END_MESSAGE_MAP()


// Gauss_seDlg 消息处理程序
