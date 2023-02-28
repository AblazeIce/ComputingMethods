// LU_2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "CM2.0.h"
#include "LU_2Dlg.h"
#include "afxdialogex.h"


// LU_2Dlg 对话框

IMPLEMENT_DYNAMIC(LU_2Dlg, CDialogEx)

LU_2Dlg::LU_2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LU_2, pParent)
	, n(3)
	, x11(2)
	, x12(-1)
	, x13(-1)
	, x14(4)
	, x21(3)
	, x22(4)
	, x23(-2)
	, x24(11)
	, x31(3)
	, x32(-2)
	, x33(4)
	, x34(11)
{

}

LU_2Dlg::~LU_2Dlg()
{
}

void LU_2Dlg::DoDataExchange(CDataExchange* pDX)
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


BEGIN_MESSAGE_MAP(LU_2Dlg, CDialogEx)
END_MESSAGE_MAP()


// LU_2Dlg 消息处理程序
