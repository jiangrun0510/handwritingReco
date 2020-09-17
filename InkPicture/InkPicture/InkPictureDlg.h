
// InkPictureDlg.h : ͷ�ļ�
//

#pragma once


// CInkPictureDlg �Ի���
class CInkPictureDlg : public CDialogEx
{
// ����
public:
	CInkPictureDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_INKPICTURE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
