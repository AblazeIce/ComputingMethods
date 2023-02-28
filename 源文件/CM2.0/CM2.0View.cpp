
// CM2.0View.cpp: CCM20View 类的实现
//

#pragma region 牛顿迭代
#include	<stdio.h>
#include	<conio.h>
#include	<math.h>
#pragma endregion

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CM2.0.h"
#endif

#include "CM2.0Doc.h"
#include "CM2.0View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "NewtonDieDaiDlg.h"
#include "TwoSideDlg.h"





//#include "Expressi.cpp"
//#define PRECISION	0.000001
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#include "JacobiDieDaiDlg.h"
#include "LagrangeDlg.h"
#include "Gauss_noDlg.h"
#include "Gauss_seDlg.h"
#include "LU_1Dlg.h"
#include "LU_2Dlg.h"
#include "T_Dlg.h"
#include "EulerDlg.h"
#include "SimpleDieDaiDlg.h"




IMPLEMENT_DYNCREATE(CCM20View, CView)

BEGIN_MESSAGE_MAP(CCM20View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	//ON_COMMAND(ID_1_01, &CCM20View::On101)
	ON_COMMAND(ID_1_03, &CCM20View::On103)
	ON_COMMAND(ID_1_02, &CCM20View::On102)
	ON_COMMAND(ID_4_01, &CCM20View::On401)
	ON_COMMAND(ID_2_01, &CCM20View::On201)
	ON_COMMAND(ID_2_02, &CCM20View::On202)
	ON_COMMAND(ID_2_03, &CCM20View::On203)
	ON_COMMAND(ID_2_04, &CCM20View::On204)
	ON_COMMAND(ID_2_05, &CCM20View::On205)
	ON_COMMAND(ID_2_06, &CCM20View::On206)
	ON_COMMAND(ID_5_01, &CCM20View::On501)
	ON_COMMAND(ID_5_02, &CCM20View::On502)
	ON_COMMAND(ID_6_01, &CCM20View::On601)
	ON_COMMAND(ID_6_02, &CCM20View::On602)
	ON_COMMAND(ID_1_TS, &CCM20View::On1Ts)
END_MESSAGE_MAP()

// CCM20View 构造/析构

CCM20View::CCM20View() noexcept
{
	// TODO: 在此处添加构造代码

	chose = 0;
	sOut = _T("");
	float_x0 = 0.0f;
	h = 0;
	m_twoside_fangcheng = _T("");
	m_twoside_x1 = 0.0f;
	m_twoside_x2 = 0.0f;

	lagrange_x = 0.0f;
	n0 = 0;
	h1 = 0;
}

CCM20View::~CCM20View()
{
}

BOOL CCM20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCM20View 绘图

void CCM20View::OnDraw(CDC* pDC)
{
	CCM20Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	/*sOut.Format(_T("你好%f"), float_x0);
	pDC->TextOutW(20, h, sOut);
	h += 20;*/
	h = 20;
	h1 = 20;
	switch (chose)
	{
	case 1:
		Newtonmain(pDC, float_x0);
		break;
	case 2:
		LagrangeMain(pDC);
	case 3:
		//TwoSideMain(pDC);
		_TwoSideMain(pDC, m_twoside_x1, m_twoside_x2);

		break;
	case 4:
		JacobiMain(pDC);
		break;
	case 5:
		JacobiMain(pDC);
		break;
	case 6:
		Gauss_no_main(pDC);
		break;
	case 7:
		Gauss_se_main(pDC);
		break;
	case 8:
		LU_1_Main(pDC);
		break;
	case 9:
		LU_2_Main(pDC);
		break;
	case 10:
		T_main(pDC,m_twoside_x1,m_twoside_x2,n0);
		break;
	case 11:
		S_main(pDC,m_twoside_x1,m_twoside_x2,n0);
		break;
	case 12:
		Euler_main(pDC,m_twoside_x1,m_twoside_x2,float_x0,n0);
		break;
	case 13:
		//S_main(pDC,m_twoside_x1,m_twoside_x2,n0);
		Improved_Euler_main(pDC, m_twoside_x1, m_twoside_x2, float_x0, n0);
		break;
	case 16:
		SimpleMain(pDC, m_twoside_x1);
		break;
	default:
		break;
	}

	// TODO: 在此处为本机数据添加绘制代码
}


// CCM20View 打印

BOOL CCM20View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCM20View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCM20View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCM20View 诊断

#ifdef _DEBUG
void CCM20View::AssertValid() const
{
	CView::AssertValid();
}

void CCM20View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCM20Doc* CCM20View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCM20Doc)));
	return (CCM20Doc*)m_pDocument;
}
#endif //_DEBUG


// CCM20View 消息处理程序


//void CCM20View::On101()
//{
//	// TODO: 在此添加命令处理程序代码
//	TwoSideDlg Dlg;
//	if (IDOK == Dlg.DoModal()) {
//		chose = 14;
//		m_twoside_x1 = Dlg.a;
//		m_twoside_x2 = Dlg.b;
//	}
//
//}


void CCM20View::On103()
{
	// TODO: 在此添加命令处理程序代码
	NewtonDieDaiDlg Dlg;
	if (IDOK == Dlg.DoModal()) {
		chose = 1;
		float_x0 = Dlg.m_diedaichuzhi;
	}
	Invalidate(true);
}
#pragma region 牛顿迭代函数部分
float CCM20View::f(float x)  //函数f(x)
{
	return(x * x * x - x - 1);
}

float CCM20View::df(float x) //函数f(x)的导数f'(x)
{
	return(3 * x * x - 1);
}

void CCM20View::NewtonIterative(CDC*pDC,float m)
{
	int k;
	float x0, x;

	printf("\n\nInput Initial Value:\nx0=");
	sOut.Format(_T("Input Initial Value:x0=%f"),m);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	//scanf("%f", &x);
	x = m;

	k = 1;
	do {
		x0 = x;
		x = x0 - f(x0) / df(x0);
		//printf("\nx%d=%f", k, x);
		sOut.Format(_T("x%d=%f"), k, x);
		pDC->TextOutW(20, h, sOut);
		h += 20;
		++k;
	} while (fabs(x - x0) > PRECISION && k < MAX_Number);

	if (k >= MAX_Number)
		//printf("Simple Iterative failed(k=%d)", k);
	{
		sOut.Format(_T("Simple Iterative failed(k=%d)"), k);
		pDC->TextOutW(20, h, sOut);
		h += 20;
	}
	else
	{
		//printf("\n\nIterative times k=%d", k);
		//printf("\nRoot x=%f", x);
		sOut.Format(_T("Iterative times k=%d"), k);
		pDC->TextOutW(20, h, sOut);
		h += 20; 
		sOut.Format(_T("Root x=%f"), x);
		pDC->TextOutW(20, h, sOut);
		h += 20;
	}
}

void CCM20View::Newtonmain(CDC*pDC,float f)
{
	NewtonIterative(pDC,f);

	//printf("\n\n\007Press any key to quit!\n");
	sOut.Format(_T("Press any key to quit!"));
	pDC->TextOutW(20, h, sOut);
	h += 20;
}
#pragma endregion




void CCM20View::On401()
{
	// TODO: 在此添加命令处理程序代码
	LagrangeDlg Dlg;
	if (IDOK == Dlg.DoModal()) {
		chose = 2;
		n0 = Dlg.n;
		x[0] = Dlg.x0;
		y[0] = Dlg.y0;
		x[1] = Dlg.x1;
		y[1]= Dlg.y1;
		x[2] = Dlg.x2;
		y[2]= Dlg.y2;
		lagrange_x = Dlg.x;
	}
	Invalidate(true);
}
#pragma region 拉格朗日插值
int CCM20View::Check_x_is_same_as_former(Point Table[], int i)
{
	int k;

	for (k = 0; k < i; ++k)
		if (fabs(Table[k].x - Table[i].x) < 0.000001) return 1;
	return 0;
}

void CCM20View::InputTable(CDC* pDC, Point Table[], int* n)
{
	int i;

	//printf("\nNumber of Points n=");
	sOut.Format(_T("Number of Points n=%d"), n0);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	//scanf("%d", n);
	*n = n0;

	for (i = 0; i < *n; ++i)
	{
		//printf("Input %dth Point(x%d,y%d): ", i, i, i);
		
		//scanf("%f,%f", &Table[i].x, &Table[i].y);
		Table[i].x = x[i];
		Table[i].y = y[i];
		sOut.Format(_T("Input %dth Point(x%d,y%d):%f,%f "), i, i, i, Table[i].x, Table[i].y);
		pDC->TextOutW(20, h, sOut);
		h += 20;
		if (Check_x_is_same_as_former(Table, i))
		{
			//printf("\nThis x is the same as the former, ReInput!\n", i);
			sOut.Format(_T("This x is the same as the former, ReInput!"), i);
			pDC->TextOutW(20, h, sOut);
			h += 20;
			--i;
		}
	}
}

float CCM20View::Lagrange(Point Table[], int n, float x)
{
	float Result, tmp;
	int i, j;

	Result = 0.0;
	for (i = 0; i < n; ++i)
	{
		tmp = 1.0;
		for (j = 0; j < n; ++j)
		{
			if (j == i)continue;
			tmp *= ((x - Table[j].x) / (Table[i].x - Table[j].x));
		}
		Result += (tmp * Table[i].y);
	}
	return(Result);
}

void CCM20View::LagrangeMain(CDC*pDC)
{
	int n;
	float x, y;
	Point Table[1000];

	InputTable(pDC,Table, &n);
	//printf("\nInput x=");
	sOut.Format(_T("Input x=%f"), lagrange_x);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	//scanf("%f", &x);
	x = lagrange_x;

	y = Lagrange(Table, n, x);

	//printf("\nL(%f)=%f", x, y);
	sOut.Format(_T("L(%f)=%f"), x,y);
	pDC->TextOutW(20, h, sOut);
	h += 20;

	//outtextxy(1, 468, "Press any key to quit!");
	sOut.Format(_T("Press any key to quit!"));
	pDC->TextOutW(20, h, sOut);
	h += 20;
	closegraph();
}
#pragma endregion

void CCM20View::On201()
{
	// TODO: 在此添加命令处理程序代码
	JacobiDieDaiDlg Dlg;
	if (IDOK == Dlg.DoModal()) {
		chose = 4;
		x0_Jacobi[0] = Dlg.x0_1;
		x0_Jacobi[1] = Dlg.x0_2;
		x0_Jacobi[2] = Dlg.x0_3;
		A_Jacobi[0][0] = Dlg.x11;
		A_Jacobi[0][1] = Dlg.x12;
		A_Jacobi[0][2] = Dlg.x13;
		A_Jacobi[0][3] = Dlg.x14;
		A_Jacobi[1][0] = Dlg.x21;
		A_Jacobi[1][1] = Dlg.x22;
		A_Jacobi[1][2] = Dlg.x23;
		A_Jacobi[1][3] = Dlg.x24;
		A_Jacobi[2][0] = Dlg.x31;
		A_Jacobi[2][1] = Dlg.x32;
		A_Jacobi[2][2] = Dlg.x33;
		A_Jacobi[2][3] = Dlg.x34;

	}
	Invalidate(true);
}
#pragma region Jacobi迭代

void CCM20View::VectorInput(CDC*pDC,float x[], int n)
{
	int i;

	for (i = 1; i <= n; ++i)
	{
		//printf("x[%d]=", i);
		x[i] = x0_Jacobi[i-1];
		sOut.Format(_T("x[%d]=%f"),i,x[i]);
		pDC->TextOutW(20, h, sOut);
		h += 20;
		//scanf("%f", &x[i]);
	}
}

void CCM20View::MatrixInput(CDC* pDC, float A[][MAX_n], int m, int n)
{
	int i, j;
	//printf("\n===Begin input Matrix elements===\n");
	sOut.Format(_T("===Begin input Matrix elements==="));
	pDC->TextOutW(20, h, sOut);
	h += 20;
	for (i = 1; i <= m; ++i)
	{
		//printf("Input_Line %d : ", i);
		for (j = 1; j <= n; ++j)
			//scanf("%f", &A[i][j])
		{
			A[i][j] = A_Jacobi[i - 1][j - 1];
		}
		sOut.Format(_T("Input_Line %d :%0.1f %0.1f %0.1f %0.1f"),i,A[i][1],A[i][2],A[i][3],A[i][4]);
		pDC->TextOutW(20, h, sOut);
		h += 20;
		
	}
}

void CCM20View::VectorOutput(CDC* pDC, float x[], int n)
{
	int i;
	for (i = 1; i <= n; ++i)
		//printf("\nx[%d]=%f", i, x[i]);
	{
		sOut.Format(_T("x[%d]=%f"), i, x[i]);
		pDC->TextOutW(400, h1, sOut);
		h1 += 20;
	}
}

int CCM20View::IsSatisfyPricision(float x1[], float x2[], int n)
{
	int i;

	for (i = 1; i <= n; ++i)
		if (fabs(x1[i] - x2[i]) > PRECISION) return 1;
	return 0;
}

int CCM20View::Jacobi_(CDC* pDC, float A[][MAX_n], float x[], int n)
{
	float x_former[MAX_n];
	int i, j, k;

	//printf("\nInput vector x0:\n");
	sOut.Format(_T("Input vector x0:"));
	pDC->TextOutW(20, h, sOut);
	h += 20;
	VectorInput(pDC,x, n);

	k = 0;
	do {
		for (i = 1; i <= n; ++i)
		{
			//printf("\nx[%d]=%f", i, x[i]);
			sOut.Format(_T("x[%d]=%f"), i, x[i]);
			pDC->TextOutW(20, h, sOut);
			h += 20;
			x_former[i] = x[i];
		}
		//printf("\n");
		for (i = 1; i <= n; ++i)
		{
			x[i] = A[i][n + 1];
			for (j = 1; j <= n; ++j)
				if (j != i)x[i] -= A[i][j] * x_former[j];
			if (fabs(A[i][i]) > PRECISION)
				x[i] /= A[i][i];
			else
				return 1;
		}
		++k;
	} while (IsSatisfyPricision(x, x_former, n) && k < MAX_Number_Jacobi);

	if (k >= MAX_Number_Jacobi)
		return 1;
	else
	{
		//printf("\nJacobi %d times!", k);
		if (chose==4)
		{
			sOut.Format(_T("Jacobi %d times!"), k);
			pDC->TextOutW(400, h1, sOut);
			h1 += 20;
		}
		else if (chose==5)
		{
			sOut.Format(_T("G-S %d times!"), k);
			pDC->TextOutW(400, h1, sOut);
			h1 += 20;
		}
		
		return 0;
	}
}

void CCM20View::JacobiMain(CDC* pDC)
{
	int n=3;
	float A[MAX_n][MAX_n], x[MAX_n];

	//printf("\nInput n=");
	sOut.Format(_T("Input n=%d"),n);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	//scanf("%d", &n);
	if (n >= MAX_n - 1)
	{
		//printf("\n\007n must <%d!", MAX_n);
		sOut.Format(_T("n must <%d!"), MAX_n);
		pDC->TextOutW(20, h, sOut);
		h += 20;
		exit(0);
	}

	MatrixInput(pDC,A, n, n + 1);

	if (Jacobi_(pDC,A, x, n))
		//printf("\nJacobi Failed!");{
	{
		if (chose == 4) {
			sOut.Format(_T("Jacobi Failed!"));
			pDC->TextOutW(400, h1, sOut);
			h1 += 20;
		}
		else if (chose==5)
		{
			sOut.Format(_T("G-S Failed!"));
			pDC->TextOutW(400, h1, sOut);
			h1 += 20;
		}
		
	}
	else
	{
		//printf("\nOutput Solution:");
		sOut.Format(_T("Output Solution:"));
		pDC->TextOutW(400, h1, sOut);
		h1 += 20;
		VectorOutput(pDC,x, n);
	}
	//printf("\n\n\007Press any key to quit!\n");
	sOut.Format(_T("Press any key to quit!"));
	pDC->TextOutW(400, h1, sOut);
	h1 += 20;
}

#pragma endregion
#pragma region Gauss_Seidel

#pragma endregion

void CCM20View::On202()
{
	// TODO: 在此添加命令处理程序代码
	JacobiDieDaiDlg Dlg;
	//SetDlgItemTextW(IDD_Jacobi, _T("nihao"));
	if (IDOK == Dlg.DoModal()) {
		chose = 5;
		x0_Jacobi[0] = Dlg.x0_1;
		x0_Jacobi[1] = Dlg.x0_2;
		x0_Jacobi[2] = Dlg.x0_3;
		A_Jacobi[0][0] = Dlg.x11;
		A_Jacobi[0][1] = Dlg.x12;
		A_Jacobi[0][2] = Dlg.x13;
		A_Jacobi[0][3] = Dlg.x14;
		A_Jacobi[1][0] = Dlg.x21;
		A_Jacobi[1][1] = Dlg.x22;
		A_Jacobi[1][2] = Dlg.x23;
		A_Jacobi[1][3] = Dlg.x24;
		A_Jacobi[2][0] = Dlg.x31;
		A_Jacobi[2][1] = Dlg.x32;
		A_Jacobi[2][2] = Dlg.x33;
		A_Jacobi[2][3] = Dlg.x34;

	}
	Invalidate(true);
}
#pragma region Gauss消元法-不选主元

void CCM20View::MatrixOneColumnOutput(CDC*pDC,float A[][MAX_n], int n, int k)
{
	int i;

	for (i = 1; i <= n; ++i)
		//printf("\nx[%d]=%f", i, A[i][k]);
	{
		sOut.Format(_T("x[%d]=%f"), i, A[i][k]);
		pDC->TextOutW(20, h, sOut);
		h += 20;
	}
}

int CCM20View::UpTriangle(float U[][MAX_n], int n)
{
	int i, j;
	for (i = n; i > 0; --i)
	{
		if (fabs(U[i][i]) < PRECISION)return 1;
		for (j = i + 1; j <= n; ++j)
			U[i][n + 1] -= U[i][j] * U[j][n + 1];
		U[i][n + 1] /= U[i][i];
	}
	return 0;
}

int CCM20View::GaussElimination(float A[][MAX_n], int n)
{
	int i, j, k;
	for (i = 1; i < n; ++i)
	{
		if (fabs(A[i][i]) < PRECISION) return 1;
		for (j = i + 1; j <= n; ++j)
			for (k = i + 1; k <= n + 1; ++k)
				A[j][k] -= A[i][k] * A[j][i] / A[i][i];
	}
	UpTriangle(A, n);
	return 0;
}

void CCM20View::Gauss_no_main(CDC*pDC)
{
	int n=3;
	float A[MAX_n][MAX_n];

	//printf("\nInput n=");
	sOut.Format(_T("Input n=%d"),n);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	//scanf("%d", &n);
	if (n >= MAX_n - 1)
	{
		//printf("\n\007n must <%d!", MAX_n);
		sOut.Format(_T("n must <%d!"), MAX_n);
		pDC->TextOutW(20, h, sOut);
		h += 20;
		exit(0);
	}

	MatrixInput(pDC,A, n, n + 1);

	if (GaussElimination(A, n))
		//printf("\nGauss Failed!");
	{
		sOut.Format(_T("Gauss Failed!"));
		pDC->TextOutW(20, h, sOut);
		h += 20;
	}
	else
	{
		//printf("\nOutput Solution:");
		sOut.Format(_T("Output Solution:"));
		pDC->TextOutW(20, h, sOut);
		h += 20;
		MatrixOneColumnOutput(pDC,A, n, n + 1);
	}
	//printf("\n\n\007Press any key to quit!\n");
	sOut.Format(_T("Press any key to quit!"));
	pDC->TextOutW(20, h, sOut);
	h += 20;
}
#pragma endregion


void CCM20View::On203()
{
	// TODO: 在此添加命令处理程序代码
	Gauss_noDlg Dlg;
	//SetDlgItemTextW(IDD_Jacobi, _T("nihao"));
	if (IDOK == Dlg.DoModal()) {
		chose = 6;
		A_Jacobi[0][0] = Dlg.x11;
		A_Jacobi[0][1] = Dlg.x12;
		A_Jacobi[0][2] = Dlg.x13;
		A_Jacobi[0][3] = Dlg.x14;
		A_Jacobi[1][0] = Dlg.x21;
		A_Jacobi[1][1] = Dlg.x22;
		A_Jacobi[1][2] = Dlg.x23;
		A_Jacobi[1][3] = Dlg.x24;
		A_Jacobi[2][0] = Dlg.x31;
		A_Jacobi[2][1] = Dlg.x32;
		A_Jacobi[2][2] = Dlg.x33;
		A_Jacobi[2][3] = Dlg.x34;

	}
	Invalidate(true);
}
#pragma region Guass消元法-列选主元
void CCM20View::Swap(float* a, float* b)
{
	float ftmp;
	ftmp = *a;
	*a = *b;
	*b = ftmp;
}
void CCM20View::Gauss_se_MatrixInput(CDC* pDC, float A[][MAX_n], int m, int n)
{
	int i, j;
	//printf("\n===Begin input Matrix elements===\n");
	sOut.Format(_T("===Begin input Matrix elements==="));
	pDC->TextOutW(20, h, sOut);
	h += 20;
	for (i = 1; i <= m; ++i)
	{
		//printf("Input_Line %d : ", i);
		for (j = 1; j <= n; ++j)
			//scanf("%f", &A[i][j])
		{
			A[i][j] = A_Jacobi[i - 1][j - 1];
		}
		sOut.Format(_T("Input_Line %d :%f %f %f %f %f"), i, A[i][1], A[i][2], A[i][3], A[i][4],A[i][5]);
		pDC->TextOutW(20, h, sOut);
		h += 20;

	}
}

int CCM20View::GaussElimination_column_select(float A[][MAX_n], int n)
{
	int i, j, k;
	float fTmp;
	for (i = 1; i < n; ++i)
	{
		//-------------------------------------------
		for (k = i, j = i + 1; j <= n; ++j)
			if (fabs(A[j][i]) > fabs(A[k][i]))	k = j;
		for (j = i; j <= n + 1; ++j)
			Swap(&A[i][j], &A[k][j]);
		//-------------------------------------------
		if (fabs(A[i][i]) < PRECISION)return 1;
		for (j = i + 1; j <= n; ++j)
			for (k = i + 1; k <= n + 1; ++k)
				A[j][k] -= A[i][k] * A[j][i] / A[i][i];
	}
	UpTriangle(A, n);
	return 0;
}
void CCM20View::Gauss_se_main(CDC* pDC)
{
	int n = 4;
	float A[MAX_n][MAX_n];

	//printf("\nInput n=");
	sOut.Format(_T("Input n=%d"), n);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	//scanf("%d", &n);
	if (n >= MAX_n - 1)
	{
		//printf("\n\007n must <%d!", MAX_n);
		sOut.Format(_T("n must <%d!"), MAX_n);
		pDC->TextOutW(20, h, sOut);
		h += 20;
		exit(0);
	}

	Gauss_se_MatrixInput(pDC, A, n, n + 1);

	if (GaussElimination_column_select(A, n))
		//printf("\nGauss Failed!");
	{
		sOut.Format(_T("Gauss Failed!"));
		pDC->TextOutW(20, h, sOut);
		h += 20;
	}
	else
	{
		//printf("\nOutput Solution:");
		sOut.Format(_T("Output Solution:"));
		pDC->TextOutW(20, h, sOut);
		h += 20;
		MatrixOneColumnOutput(pDC, A, n, n + 1);
	}
	//printf("\n\n\007Press any key to quit!\n");
	sOut.Format(_T("Press any key to quit!"));
	pDC->TextOutW(20, h, sOut);
	h += 20;
}
#pragma endregion



void CCM20View::On204()
{
	// TODO: 在此添加命令处理程序代码
	Gauss_seDlg Dlg;
	//SetDlgItemTextW(IDD_Jacobi, _T("nihao"));
	if (IDOK == Dlg.DoModal()) {
		chose = 7;
		A_Jacobi[0][0] = Dlg.x11;
		A_Jacobi[0][1] = Dlg.x12;
		A_Jacobi[0][2] = Dlg.x13;
		A_Jacobi[0][3] = Dlg.x14;
		A_Jacobi[0][4] = Dlg.x15;
		A_Jacobi[1][0] = Dlg.x21;
		A_Jacobi[1][1] = Dlg.x22;
		A_Jacobi[1][2] = Dlg.x23;
		A_Jacobi[1][3] = Dlg.x24;
		A_Jacobi[1][4] = Dlg.x25;
		A_Jacobi[2][0] = Dlg.x31;
		A_Jacobi[2][1] = Dlg.x32;
		A_Jacobi[2][2] = Dlg.x33;
		A_Jacobi[2][3] = Dlg.x34;
		A_Jacobi[2][4] = Dlg.x35;
		A_Jacobi[3][0] = Dlg.x41;
		A_Jacobi[3][1] = Dlg.x42;
		A_Jacobi[3][2] = Dlg.x43;
		A_Jacobi[3][3] = Dlg.x44;
		A_Jacobi[3][4] = Dlg.x45;

	}
	Invalidate(true);
}
#pragma region 矩阵的LU分解
int CCM20View::LU_De_no_select(float A[][MAX_n], int n)
{
	int i, j, k, r;
	for (r = 1; r < n; ++r)
	{
		for (i = r + 1; i <= n; ++i)
		{
			if (fabs(A[r][r]) < PRECISION) return 1;
			for (k = 1; k < r; ++k)
				A[i][r] -= A[i][k] * A[k][r];
			A[i][r] /= A[r][r];
		}
		for (i = r + 1; i <= n; ++i)
			for (k = 1; k <= r; ++k)
				A[r + 1][i] -= A[r + 1][k] * A[k][i];
	}
	return 0;
}

void CCM20View::LowTriaMatrixOutput(CDC*pDC,float A[][MAX_n], int n)
{
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		h1 = 20;

		//printf("\n");
		for (j = 1; j <= n; ++j)
		{
			if (j < i)
				//printf("%f\t", A[i][j]);
			{
				sOut.Format(_T("%f"), A[i][j]);
				pDC->TextOutW(h1, h, sOut);
				h1 += 100;
			}
			else if (j == i) {
				sOut.Format(_T("%f"), 1.);
				pDC->TextOutW(h1, h, sOut);
				h1 += 100;
			}
				//printf("%f\t", 1.);
			else {
				sOut.Format(_T("%f"), 0.);
				pDC->TextOutW(h1, h, sOut);
				h1 += 100;
			}
				//printf("%f\t", 0.);
		}
		h += 20;
	}
	h += 20;
}

void CCM20View::UpTriaMatrixOutput(CDC*pDC,float A[][MAX_n], int n)
{
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		h1 = 20;

		//printf("\n");
		for (j = 1; j <= n; ++j)
		{
			if (j >= i) {
				sOut.Format(_T("%f"), A[i][j]);
				pDC->TextOutW(h1, h, sOut);
				h1 += 100;
			}
				//printf("%f\t", A[i][j]);
			else {
				sOut.Format(_T("%f"), 0.);
				pDC->TextOutW(h1, h, sOut);
				h1 += 100;
			}
				//printf("%f\t", 0.);
		}
		h += 20;
	}
	h += 20;
}

void CCM20View::LU_1_Main(CDC*pDC)
{
	int n=3;
	float A[MAX_n][MAX_n];

	//printf("\nInput n=");
	sOut.Format(_T("Input n=%d"), n);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	//scanf("%d", &n);
	if (n >= MAX_n - 1)
	{
		//printf("\n\007n must <%d!", MAX_n);
		sOut.Format(_T("n must <%d!"), MAX_n);
		pDC->TextOutW(20, h, sOut);
		h += 20;
		exit(0);
	}

	MatrixInput(pDC,A, n, n);
	if (LU_De_no_select(A, n)) {
		sOut.Format(_T("LU Failt!"));
		pDC->TextOutW(20, h, sOut);
		h += 20;
	}
		//printf("\nLU Failt!");
	else
	{
		//printf("\nOutput L:");
		sOut.Format(_T("Output L:"));
		pDC->TextOutW(20, h, sOut);
		h += 20;
		LowTriaMatrixOutput(pDC,A, n);
		//printf("\nOutput U:");
		sOut.Format(_T("Output U:"));
		pDC->TextOutW(20, h, sOut);
		h += 20;
		UpTriaMatrixOutput(pDC,A, n);
	}
	//printf("\n\n\007Press any key to quit!\n");
	sOut.Format(_T("Press any key to quit!"));
	pDC->TextOutW(20, h, sOut);
	h += 20;
}
#pragma endregion


void CCM20View::On205()
{
	// TODO: 在此添加命令处理程序代码
	LU_1Dlg Dlg;
	//SetDlgItemTextW(IDD_Jacobi, _T("nihao"));
	if (IDOK == Dlg.DoModal()) {
		chose = 8;
		A_Jacobi[0][0] = Dlg.x11;
		A_Jacobi[0][1] = Dlg.x12;
		A_Jacobi[0][2] = Dlg.x13;
		A_Jacobi[1][0] = Dlg.x21;
		A_Jacobi[1][1] = Dlg.x22;
		A_Jacobi[1][2] = Dlg.x23;
		A_Jacobi[2][0] = Dlg.x31;
		A_Jacobi[2][1] = Dlg.x32;
		A_Jacobi[2][2] = Dlg.x33;

	}
	Invalidate(true);
}
#pragma region LU分解法求解方程组的解
int CCM20View::LowTriangle_1(float L[][MAX_n], int n)
{
	int i, j;
	for (i = 1; i <= n; ++i)
		//	{
		//		if(fabs(L[i][i])<PRECISION)return 1;
		for (j = 1; j < i; ++j)
			L[i][n + 1] -= L[i][j] * L[j][n + 1];
	//		L[i][n+1]/=L[i][i];
	//	}
	return 0;

}
void CCM20View::LU_2_Main(CDC*pDC)
{
	int n=3;
	float A[MAX_n][MAX_n];
	sOut.Format(_T("Input n=%d"),n);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	//printf("\nInput n=");
	//scanf("%d", &n);
	if (n >= MAX_n - 1)
	{
		//printf("\n\007n must <%d!", MAX_n);
		sOut.Format(_T("n must <%d!"), MAX_n);
		pDC->TextOutW(20, h, sOut);
		h += 20;
		exit(0);
	}

	MatrixInput(pDC,A, n, n + 1);
	if (LU_De_no_select(A, n))
	{
		sOut.Format(_T("LU Failt!"));
		pDC->TextOutW(20, h, sOut);
		h += 20;
	}
		//printf("\nLU Failt!");
	else
	{
		LowTriangle_1(A, n);
		if (UpTriangle(A, n)) {
			sOut.Format(_T("LU Failt!"));
			pDC->TextOutW(20, h, sOut);
			h += 20;
		}
			//printf("\nLU Failt!");
		else
		{
			MatrixOneColumnOutput(pDC,A, n, n + 1);
		}
		//		printf("\nOutput L:");
		//		LowTriaMatrixOutput(A,n);
		//		printf("\nOutput U:");
		//		UpTriaMatrixOutput(A,n);

	}
	//printf("\n\n\007Press any key to quit!\n");
	sOut.Format(_T("Press any key to quit!\n"));
	pDC->TextOutW(20, h, sOut);
	h += 20;
}
#pragma endregion


void CCM20View::On206()
{
	// TODO: 在此添加命令处理程序代码
	LU_2Dlg Dlg;
	//SetDlgItemTextW(IDD_Jacobi, _T("nihao"));
	if (IDOK == Dlg.DoModal()) {
		chose = 9;
		A_Jacobi[0][0] = Dlg.x11;
		A_Jacobi[0][1] = Dlg.x12;
		A_Jacobi[0][2] = Dlg.x13;
		A_Jacobi[0][3] = Dlg.x14;
		A_Jacobi[1][0] = Dlg.x21;
		A_Jacobi[1][1] = Dlg.x22;
		A_Jacobi[1][2] = Dlg.x23;
		A_Jacobi[1][3] = Dlg.x24;
		A_Jacobi[2][0] = Dlg.x31;
		A_Jacobi[2][1] = Dlg.x32;
		A_Jacobi[2][2] = Dlg.x33;
		A_Jacobi[2][3] = Dlg.x34;

	}
	Invalidate(true);
}
#pragma region 复合T型求积公式
float CCM20View::RepeatT(float a, float b, int n)
{
	int i;
	float h, Value;

	if (n <= 0) return 0;
	h = (b - a) / n;
	Value = 0;
	for (i = 1; i < n; ++i)
		Value += f1(a + i * h);
	return((f1(a) + f1(b) + 2 * Value) * h / 2);
}
float CCM20View::f1(float x) {
	return 1 / (1 + x);
}
void CCM20View::T_main(CDC*pDC,float a,float b,float n)
{
	float i1;
	char FxString[200];
	
	//printf("\nInput function,a,b,n: ");
	//scanf("%s %f %f %d", FxString, &a, &b, &n);
	sOut.Format(_T("Input function,a,b,n:%f,%f,%d"), a, b, n);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	i1 = RepeatT(a, b, n);

	//printf("\n%f", i1);
	sOut.Format(_T("%f"), i1);
	pDC->TextOutW(20, h, sOut);
	h += 20;

}
#pragma endregion



void CCM20View::On501()
{
	// TODO: 在此添加命令处理程序代码
	T_Dlg Dlg;
	//SetDlgItemTextW(IDD_Jacobi, _T("nihao"));
	if (IDOK == Dlg.DoModal()) {
		chose = 10;
		m_twoside_x1 = Dlg.a;
		m_twoside_x2 = Dlg.b;
		n0 = Dlg.n;
	}
	Invalidate(true);
}
#pragma region 复合Simpson求积公式
float CCM20View::RepeatS(float a, float b, int n)
{
	int i;
	float h, Value1, Value2;

	if (n <= 0) return 0;
	h = (b - a) / n;

	Value1 = 0;
	Value2 = 0;
	for (i = 0; i < n; ++i)
		Value1 += f1(a + (i + 0.5) * h);
	for (i = 1; i < n; ++i)
		Value2 += f1(a + i * h);
	return((f1(a) + f1(b) + 4 * Value1 + 2 * Value2) * h / 6);
}
void CCM20View::S_main(CDC* pDC, float a, float b, float n)
{
	float i1;
	char FxString[200];

	//printf("\nInput function,a,b,n: ");
	//scanf("%s %f %f %d", FxString, &a, &b, &n);
	sOut.Format(_T("Input function,a,b,n:%f,%f,%d"), a, b, n);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	i1 = RepeatS(a, b, n);

	//printf("\n%f", i1);
	sOut.Format(_T("%f"), i1);
	pDC->TextOutW(20, h, sOut);
	h += 20;

}
#pragma endregion


void CCM20View::On502()
{
	// TODO: 在此添加命令处理程序代码
	T_Dlg Dlg;
	//SetDlgItemTextW(IDD_Jacobi, _T("nihao"));
	if (IDOK == Dlg.DoModal()) {
		chose = 11;
		m_twoside_x1 = Dlg.a;
		m_twoside_x2 = Dlg.b;
		n0 = Dlg.n;
	}
	Invalidate(true);
}


void CCM20View::On601()
{
	// TODO: 在此添加命令处理程序代码
	EulerDlg Dlg;
	//SetDlgItemTextW(IDD_Jacobi, _T("nihao"));
	if (IDOK == Dlg.DoModal()) {
		chose = 12;
		m_twoside_x1 = Dlg.x0;
		m_twoside_x2 = Dlg.y0;
		float_x0 = Dlg.h;
		n0 = Dlg.n;
	}
	Invalidate(true);
}
#pragma region 欧拉方法
void CCM20View::Euler(CDC*pDC,float x0, float y0, float h3, int n)
{
	int i;
	float yi;

	yi = y0;
	for (i = 1; i < n; ++i)
	{
		yi = yi + h3 * f2(x0 + (i - 1) * h3, yi);
		//printf("\ny%d=%f", i, yi);
		sOut.Format(_T("y%d=%f"), i, yi);
		pDC->TextOutW(20, h, sOut);
		h += 20;
	}

}
float CCM20View::f2(float x, float y) {
	return y - 2 * x / y;
}
void CCM20View::Euler_main(CDC*pDC,float x0,float y0,float h3,int n)
{
	//float x0, y0, h; //x0:自变量初值,y0:y(x0),h:步长
	//int n; //步数
	//char FxyString[200]; //存放C表达式格式的f(x,y)
	sOut.Format(_T("Input function: y-2*x/y"));
	pDC->TextOutW(20, h, sOut);
	h += 20;
	sOut.Format(_T("Input:x0=%f,y0=%f,h=%f,n=%d: "),x0,y0,h3,n);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	//printf("\nInput function,x0,y0,h,n: ");
	//scanf("%s %f %f %f %d", FxyString, &x0, &y0, &h, &n);

	Euler(pDC,x0, y0, h3, n);

}
#pragma endregion

#pragma region 改进的欧拉方法
void CCM20View::Improved_Euler(CDC* pDC, float x0, float y0, float h3, int n)
{
	int i;
	float yi,tmp;

	yi = y0;
	for (i = 1; i < n; ++i)
	{
		tmp = yi;
		yi = yi + h3 * f2(x0 + (i - 1) * h3, yi);
		//printf("\ny%d=%f", i, yi);
		yi = tmp + h3 / 2 * (f2(x0 + (i - 1) * h3, tmp) + f2(x0 + i * h3, yi));

		sOut.Format(_T("y%d=%f"), i, yi);
		pDC->TextOutW(20, h, sOut);
		h += 20;
	}

}
void CCM20View::Improved_Euler_main(CDC* pDC, float x0, float y0, float h3, int n)
{
	//float x0, y0, h; //x0:自变量初值,y0:y(x0),h:步长
	//int n; //步数
	//char FxyString[200]; //存放C表达式格式的f(x,y)
	sOut.Format(_T("Input function: y-2*x/y"));
	pDC->TextOutW(20, h, sOut);
	h += 20;
	sOut.Format(_T("Input:x0=%f,y0=%f,h=%f,n=%d: "), x0, y0, h3, n);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	//printf("\nInput function,x0,y0,h,n: ");
	//scanf("%s %f %f %f %d", FxyString, &x0, &y0, &h, &n);

	Improved_Euler(pDC, x0, y0, h3, n);

}
#pragma endregion


void CCM20View::On602()
{
	// TODO: 在此添加命令处理程序代码
	EulerDlg Dlg;
	//SetDlgItemTextW(IDD_Jacobi, _T("nihao"));
	if (IDOK == Dlg.DoModal()) {
		chose = 13;
		m_twoside_x1 = Dlg.x0;
		m_twoside_x2 = Dlg.y0;
		float_x0 = Dlg.h;
		n0 = Dlg.n;
	}
	Invalidate(true);
}




#pragma region 二分法求方程根
float CCM20View::RootByBisection(float a, float b)
{
	float x1, x2;

	//if (CreateFx(FxString)) return(0.0);
	x1 = a;
	x2 = b;

	while (fabs(x2 - x1) > PRECISION_1)
		if (f4(x1) * f4((x1 + x2) / 2) < 0)
			x2 = (x1 + x2) / 2;
		else
			x1 = (x1 + x2) / 2;

	return(x1);
}
float CCM20View::f4(float f) {
	return pow(f, 3) - f - 1;
}

void CCM20View::_TwoSideMain(CDC*pDC,float x1,float x2)
{
	//float x1, x2;
	//char FxString[200];

	//printf("\nInput function with varable x,x1,x2 : ");
	sOut.Format(_T("Input function with varable x1,x2 :%f  %f"),x1,x2);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	//scanf("%s %f %f", FxString, &x1, &x2);
	//printf("\nRoot x=%f", RootByBisection(FxString,x1, x2));
	sOut.Format(_T("Root x=%f"), RootByBisection(x1, x2));
	pDC->TextOutW(20, h, sOut);
	h += 20;
}
#pragma endregion
void CCM20View::On1Ts()
{
	// TODO: 在此添加命令处理程序代码
	TwoSideDlg Dlg;
		if (IDOK == Dlg.DoModal()) {
			chose = 3;
			m_twoside_x1 = Dlg.a;
			m_twoside_x2 = Dlg.b;
		}
		Invalidate(true);
}
#pragma region 简单迭代
float CCM20View::f3(float y) {
	return pow(y + 1, 1 / 3.);
}
void CCM20View::SimpleIterative(CDC*pDC,float y)
{
	int k;
	float x0, x;

	//if (CreateFx(FxString)) exit(0);
	x = y;
	//printf("\n\nInput Initial Value:\nx0=");
	sOut.Format(_T("Input Initial Value:x0=%f"),x);
	pDC->TextOutW(20, h, sOut);
	h += 20;
	//scanf("%f", &x);

	k = 1;
	do {
		x0 = x;
		x = f3(x0);
		//printf("\nx%d=%f", k, x);
		sOut.Format(_T("x%d=%f"),k, x);
		pDC->TextOutW(20, h, sOut);
		h += 20;
		++k;
	} while (fabs(x - x0) > PRECISION && k < MAX_Number);

	if (k >= MAX_Number) {
		sOut.Format(_T("Simple Iterative failed(k=%d)"), k);
		pDC->TextOutW(20, h, sOut);
		h += 20;
	}
		//printf("\nSimple Iterative failed(k=%d)", k);
	else
	{
		//printf("\n\nIterative times k=%d", k);
		sOut.Format(_T("Iterative times k=%d"), k);
		pDC->TextOutW(20, h, sOut);
		h += 20; 
		sOut.Format(_T("Root x=%f"),x);
		pDC->TextOutW(20, h, sOut);
		h += 20;
		//printf("\nRoot x=%f", x);
	}
}

void CCM20View::SimpleMain(CDC*pDC,float yy)
{
	//char FxString[200];

	//printf("\nInput function:  ");
	sOut.Format(_T("Input function: "));
	pDC->TextOutW(20, h, sOut);
	h += 20;
	//scanf("%s", FxString);
	SimpleIterative(pDC,yy);
	//printf("\n\n\007Press any key to quit!\n");
	sOut.Format(_T("Press any key to quit!"));
	pDC->TextOutW(20, h, sOut);
	h += 20;
}
#pragma endregion
void CCM20View::On102()
{
	// TODO: 在此添加命令处理程序代码
	SimpleDieDaiDlg Dlg;
	if (IDOK == Dlg.DoModal()) {
		chose = 16;
		m_twoside_x1 = Dlg.x0;
	}
	Invalidate(true);

}
