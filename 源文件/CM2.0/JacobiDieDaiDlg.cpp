// JacobiDieDaiDlg.cpp: 实现文件
//

#include "pch.h"
#include "CM2.0.h"
#include "JacobiDieDaiDlg.h"
#include "afxdialogex.h"


// JacobiDieDaiDlg 对话框

IMPLEMENT_DYNAMIC(JacobiDieDaiDlg, CDialogEx)

JacobiDieDaiDlg::JacobiDieDaiDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Jacobi, pParent)
	, x0_1(3)
	, x0_2(1)
	, x0_3(1)
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
	
	, n(3)
{

}

JacobiDieDaiDlg::~JacobiDieDaiDlg()
{
}

void JacobiDieDaiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT17, x0_1);
	DDX_Text(pDX, IDC_EDIT18, x0_2);
	DDX_Text(pDX, IDC_EDIT19, x0_3);
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
	DDX_Text(pDX, IDC_EDIT1, n);
}


BEGIN_MESSAGE_MAP(JacobiDieDaiDlg, CDialogEx)
END_MESSAGE_MAP()


// JacobiDieDaiDlg 消息处理程序
