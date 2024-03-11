
// MFCApplication4Dlg.h : ��� ����
//

#pragma once
#include <opencv2/opencv.hpp>
#include <time.h>
#include "afxwin.h"
using namespace std;
using namespace cv;

// CMFCApplication4Dlg ��ȭ ����
class CMFCApplication4Dlg : public CDialogEx
{
private:
	CRect getCanvasRect() const;
// �����Դϴ�.
public:
	CMFCApplication4Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	Mat m_SelectedRegion;
	Mat src;
	Mat aa;
// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };
	CPoint rect_start_pos;
	Mat a;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.
	
public:
	void DisplayImage(int IDC_PICTURE_TARGET, Mat targetMat);
	void ClientToImageCoordinates(CPoint& point);
	
// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	afx_msg void OnStnClickedPic1();
	afx_msg void OnBnClickedButton2();
	CEdit aaa;
	CEdit bbb;
	CEdit ccc;
	CEdit ddd;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	CEdit eee;
	afx_msg void OnEnChangeEdit5();
};
