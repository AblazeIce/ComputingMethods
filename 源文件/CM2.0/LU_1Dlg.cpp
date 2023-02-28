// LU_1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "CM2.0.h"
#include "LU_1Dlg.h"
#include "afxdialogex.h"


// LU_1Dlg 对话框

IMPLEMENT_DYNAMIC(LU_1Dlg, CDialogEx)

LU_1Dlg::LU_1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LU_1, pParent)
	, n(3)
	, x11(2)
	, x12(-1)
	, x13(-1)
	, x21(3)
	, x22(4)
	, x23(-2)
	, x31(3)
	, x32(-2)
	, x33(4)
{

}

LU_1Dlg::~LU_1Dlg()
{
}

void LU_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n);
	DDX_Text(pDX, IDC_EDIT3, x12);
	DDX_Text(pDX, IDC_EDIT10, x13);
	DDX_Text(pDX, IDC_EDIT6, x21);
	DDX_Text(pDX, IDC_EDIT7, x22);
	DDX_Text(pDX, IDC_EDIT12, x23);
	DDX_Text(pDX, IDC_EDIT9, x31);
	DDX_Text(pDX, IDC_EDIT15, x33);
	DDX_Text(pDX, IDC_EDIT2, x11);
	DDX_Text(pDX, IDC_EDIT14, x32);
}


BEGIN_MESSAGE_MAP(LU_1Dlg, CDialogEx)
END_MESSAGE_MAP()


// LU_1Dlg 消息处理程序
