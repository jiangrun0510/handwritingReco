
// InkPictureDlg.h : 头文件
//

#pragma once


// CInkPictureDlg 对话框
class CInkPictureDlg : public CDialogEx
{
// 构造
public:
	CInkPictureDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_INKPICTURE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void setEditingMode(short mode);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	void setPointEraseMode(bool bIsPointEraseMode);
	void setStrokeThickness(bool isThick);
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	void setColor(COLORREF color);
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};
