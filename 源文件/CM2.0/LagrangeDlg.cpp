// LagrangeDlg.cpp: 实现文件
//

#include "pch.h"
#include "CM2.0.h"
#include "LagrangeDlg.h"
#include "afxdialogex.h"


// LagrangeDlg 对话框

IMPLEMENT_DYNAMIC(LagrangeDlg, CDialogEx)

LagrangeDlg::LagrangeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Lagrange, pParent)
	, x0(100)
	, y0(10)
	, x1(121)
	, y1(11)
	, x2(144)
	, y2(12)
	, x(115)
	, n(3)
{

}

LagrangeDlg::~LagrangeDlg()
{
}

void LagrangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, x0);
	DDX_Text(pDX, IDC_EDIT6, y0);
	DDX_Text(pDX, IDC_EDIT4, x1);
	DDX_Text(pDX, IDC_EDIT7, y1);
	DDX_Text(pDX, IDC_EDIT5, x2);
	DDX_Text(pDX, IDC_EDIT8, y2);
	DDX_Text(pDX, IDC_EDIT9, x);
	DDX_Text(pDX, IDC_EDIT1, n);
}


BEGIN_MESSAGE_MAP(LagrangeDlg, CDialogEx)
END_MESSAGE_MAP()


// LagrangeDlg 消息处理程序
