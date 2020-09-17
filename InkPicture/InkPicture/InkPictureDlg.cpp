
// InkPictureDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "InkPicture.h"
#include "InkPictureDlg.h"
#include "afxdialogex.h"

#include <wtypes.h>
#include <msinkaut.h>
#include <msinkaut_i.c>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CInkPictureDlg 对话框



CInkPictureDlg::CInkPictureDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInkPictureDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInkPictureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CInkPictureDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CInkPictureDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CInkPictureDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CInkPictureDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CInkPictureDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CInkPictureDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CInkPictureDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CInkPictureDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CInkPictureDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CInkPictureDlg 消息处理程序

BOOL CInkPictureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	//设置为点擦除模式
	setPointEraseMode(true);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CInkPictureDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CInkPictureDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CInkPictureDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CInkPictureDlg::setEditingMode(short mode)
{
	CComPtr<IInkPicture> ip;
	ip.CoCreateInstance(CLSID_InkPicture);

	DISPID dispid = 0;
	OLECHAR *szMembers = OLESTR("EditingMode");

	HRESULT hr = ip->GetIDsOfNames(IID_IInkPicture, &szMembers, 1, LOCALE_SYSTEM_DEFAULT, &dispid);
	if (FAILED(hr))
	{
		AfxMessageBox(TEXT("取EditingMode  id出错"));
	}

	CWnd *InkPicture = GetDlgItem(IDC_INKPICTURE1);
	InkPicture->SetProperty(dispid, VT_I2, mode);

	ip.Release();
}


void CInkPictureDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	setEditingMode(InkOverlayEditingMode::IOEM_Ink);
}


void CInkPictureDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	setEditingMode(InkOverlayEditingMode::IOEM_Delete);
}


void CInkPictureDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	setEditingMode(InkOverlayEditingMode::IOEM_Select);
}


void CInkPictureDlg::setPointEraseMode(bool bIsPointEraseMode)
{
	CComPtr<IInkPicture> ip;
	ip.CoCreateInstance(CLSID_InkPicture);

	DISPID dispid = 0;
	OLECHAR *szMembers = OLESTR("EraserMode");

	HRESULT hr = ip->GetIDsOfNames(IID_IInkPicture, &szMembers, 1, LOCALE_SYSTEM_DEFAULT, &dispid);
	if (FAILED(hr))
	{
		AfxMessageBox(TEXT("取EreaseMode  id出错"));
	}

	CWnd *InkPicture = GetDlgItem(IDC_INKPICTURE1);

	if (bIsPointEraseMode)
	{
		InkPicture->SetProperty(dispid, VT_I2, InkOverlayEraserMode::IOERM_PointErase);
	}
	else
	{
		InkPicture->SetProperty(dispid, VT_I2, InkOverlayEraserMode::IOERM_StrokeErase);
	}


	ip.Release();
}


void CInkPictureDlg::setStrokeThickness(bool isThick)
{
	CComPtr<IInkPicture> ip;
	CComPtr<IInkDrawingAttributes> spInkDrawAttri = NULL;
	ip.CoCreateInstance(CLSID_InkPicture);

	float newWidth = isThick ? 250 : 50;

	DISPID dispid = 0;
	OLECHAR *szMembers = OLESTR("DefaultDrawingAttributes");
	HRESULT hr = ip->GetIDsOfNames(IID_IInkDrawingAttributes, &szMembers, 1, LOCALE_SYSTEM_DEFAULT, &dispid);
	if (FAILED(hr))
	{
		AfxMessageBox(TEXT("取DefaultDrawingAttributes  id出错"));
	}

	CWnd *InkPicture = GetDlgItem(IDC_INKPICTURE1);
	InkPicture->GetProperty(dispid, VT_UNKNOWN, &spInkDrawAttri);
	spInkDrawAttri->put_Width(newWidth);
	InkPicture->SetProperty(dispid, VT_DISPATCH, spInkDrawAttri);

	ip.Release();
}


void CInkPictureDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	setStrokeThickness(true);
}


void CInkPictureDlg::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	setStrokeThickness(false);
}


void CInkPictureDlg::setColor(COLORREF color)
{
	CComPtr<IInkPicture> ip;
	CComPtr<IInkDrawingAttributes> spInkDrawAttri = NULL;
	ip.CoCreateInstance(CLSID_InkPicture);

	DISPID dispid = 0;
	OLECHAR *szMembers = OLESTR("DefaultDrawingAttributes");
	HRESULT hr = ip->GetIDsOfNames(IID_IInkDrawingAttributes, &szMembers, 1, LOCALE_SYSTEM_DEFAULT, &dispid);
	if (FAILED(hr))
	{
		AfxMessageBox(TEXT("取DefaultDrawingAttributes  id出错"));
	}

	CWnd *InkPicture = GetDlgItem(IDC_INKPICTURE1);
	InkPicture->GetProperty(dispid, VT_UNKNOWN, &spInkDrawAttri);
	spInkDrawAttri->put_Color(color);
	//spInkDrawAttri->put_Width(newWidth);
	InkPicture->SetProperty(dispid, VT_DISPATCH, spInkDrawAttri);

	ip.Release();
}


void CInkPictureDlg::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	setColor(RGB(255, 0, 0));
}


void CInkPictureDlg::OnBnClickedButton7()
{
	// TODO:  在此添加控件通知处理程序代码
	setColor(RGB(0, 255, 0));
}


void CInkPictureDlg::OnBnClickedButton8()
{
	// TODO:  在此添加控件通知处理程序代码
	setColor(RGB(0, 0, 255));
}
