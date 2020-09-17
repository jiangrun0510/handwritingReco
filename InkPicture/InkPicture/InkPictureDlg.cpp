
// InkPictureDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CInkPictureDlg �Ի���



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


// CInkPictureDlg ��Ϣ�������

BOOL CInkPictureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	//����Ϊ�����ģʽ
	setPointEraseMode(true);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CInkPictureDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
		AfxMessageBox(TEXT("ȡEditingMode  id����"));
	}

	CWnd *InkPicture = GetDlgItem(IDC_INKPICTURE1);
	InkPicture->SetProperty(dispid, VT_I2, mode);

	ip.Release();
}


void CInkPictureDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	setEditingMode(InkOverlayEditingMode::IOEM_Ink);
}


void CInkPictureDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	setEditingMode(InkOverlayEditingMode::IOEM_Delete);
}


void CInkPictureDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
		AfxMessageBox(TEXT("ȡEreaseMode  id����"));
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
		AfxMessageBox(TEXT("ȡDefaultDrawingAttributes  id����"));
	}

	CWnd *InkPicture = GetDlgItem(IDC_INKPICTURE1);
	InkPicture->GetProperty(dispid, VT_UNKNOWN, &spInkDrawAttri);
	spInkDrawAttri->put_Width(newWidth);
	InkPicture->SetProperty(dispid, VT_DISPATCH, spInkDrawAttri);

	ip.Release();
}


void CInkPictureDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	setStrokeThickness(true);
}


void CInkPictureDlg::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
		AfxMessageBox(TEXT("ȡDefaultDrawingAttributes  id����"));
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	setColor(RGB(255, 0, 0));
}


void CInkPictureDlg::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	setColor(RGB(0, 255, 0));
}


void CInkPictureDlg::OnBnClickedButton8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	setColor(RGB(0, 0, 255));
}
