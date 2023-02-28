// SimpleDieDaiDlg.cpp: 实现文件
//

#include "pch.h"
#include "CM2.0.h"
#include "SimpleDieDaiDlg.h"
#include "afxdialogex.h"


// SimpleDieDaiDlg 对话框

IMPLEMENT_DYNAMIC(SimpleDieDaiDlg, CDialogEx)

SimpleDieDaiDlg::SimpleDieDaiDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SimpleDieDai, pParent)
	, function(_T("pow(x+1,1/3.)"))
	, x0(0.0)
{

}

SimpleDieDaiDlg::~SimpleDieDaiDlg()
{
}

void SimpleDieDaiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, function);
	DDX_Text(pDX, IDC_EDIT2, x0);
}


BEGIN_MESSAGE_MAP(SimpleDieDaiDlg, CDialogEx)
END_MESSAGE_MAP()


// SimpleDieDaiDlg 消息处理程序
