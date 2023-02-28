
// CM2.0View.h: CCM20View 类的接口
//

#pragma once

typedef struct {
	float x;
	float y;
} Point;
#define	MAX_n	100
#define MAX_Number_Jacobi	1000
#define PRECISION	0.0000001
#define PRECISION_1	0.000001
#define MAX_Number	10000
//#define MAX_Number_Guass_Seidel	1000
class CCM20View : public CView
{
protected: // 仅从序列化创建
	CCM20View() noexcept;
	DECLARE_DYNCREATE(CCM20View)

// 特性
public:
	CCM20Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CCM20View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void On101();
	int chose;
	CString sOut;
//	int m_twoside_x1;
	float float_x0;
	afx_msg void On103();
	int h;
	void NewtonIterative(CDC* pDC,float f);
	float df(float x);
	float f(float x);
	void Newtonmain(CDC* pDC,float f);
	//float RootByBisection(char FxString[], float a, float b);
	//void TwoSideMain(CDC*pDC);
	CString m_twoside_fangcheng;
	float m_twoside_x1;
	float m_twoside_x2;
	void On102();
	afx_msg void On401();
	int Check_x_is_same_as_former(Point Table[], int i);
	void InputTable(CDC* pDC, Point Table[], int* n);
	float Lagrange(Point Table[], int n, float x);
	void LagrangeMain(CDC* pDC);
	afx_msg void On201();
	void VectorInput(CDC* pDC, float x[], int n);
	void MatrixInput(CDC* pDC, float A[][MAX_n], int m, int n);
	void VectorOutput(CDC* pDC, float x[], int n);
	int IsSatisfyPricision(float x1[], float x2[], int n);
	int Jacobi_(CDC* pDC, float A[][MAX_n], float x[], int n);
	void MatrixOneColumnOutput(CDC* pDC, float A[][MAX_n], int n, int k);
	int UpTriangle(float U[][MAX_n], int n);
	int GaussElimination(float A[][MAX_n], int n);
	void Gauss_no_main(CDC* pDC);
	void Swap(float* a, float* b);
	int GaussElimination_column_select(float A[][MAX_n], int n);
	void Gauss_se_main(CDC* pDC);
	void Gauss_se_MatrixInput(CDC* pDC, float A[][MAX_n], int m, int n);
	void CCM20View::LU_1_Main(CDC* pDC);
	void UpTriaMatrixOutput(CDC* pDC, float A[][MAX_n], int n);
	void LowTriaMatrixOutput(CDC* pDC, float A[][MAX_n], int n);
	int LU_De_no_select(float A[][MAX_n], int n);
	int LowTriangle_1(float L[][MAX_n], int n);
	void LU_2_Main(CDC* pDC);
	float RepeatT(float a, float b, int n);
	float f1(float x);
	void T_main(CDC* pDC, float a, float b, float n);
	float RepeatS(float a, float b, int n);
	void S_main(CDC* pDC, float a, float b, float n);
	void Euler(CDC*pDC,float x0, float y0, float h, int n);
	void Improved_Euler(CDC*pDC,float x0, float y0, float h, int n);
	void Euler_main(CDC* pDC, float x0, float y0, float h, int n);
	void Improved_Euler_main(CDC* pDC, float x0, float y0, float h, int n);

	float f2(float x, float y);
	void SimpleIterative(CDC* pDC, float y);
	void SimpleMain(CDC* pDC, float yy);
	float f3(float y);
	float RootByBisection(float a, float b);
	void _TwoSideMain(CDC* pDC, float x1, float x2);
	float f4(float f);

	void JacobiMain(CDC* pDC);
	float lagrange_x;
	int n0;
	

	float x[100];
	float y[100];
	float x0_Jacobi[10];
	float A_Jacobi[10][10];
	int h1;
	afx_msg void On202();
	afx_msg void On203();
	afx_msg void On204();
	afx_msg void On205();
	afx_msg void On206();
	afx_msg void On501();
	afx_msg void On502();
	afx_msg void On601();
	afx_msg void On602();
	afx_msg void On1Ts();
};

#ifndef _DEBUG  // CM2.0View.cpp 中的调试版本
inline CCM20Doc* CCM20View::GetDocument() const
   { return reinterpret_cast<CCM20Doc*>(m_pDocument); }
#endif

