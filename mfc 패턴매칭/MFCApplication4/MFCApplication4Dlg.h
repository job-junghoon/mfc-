
// MFCApplication4Dlg.h : 헤더 파일
//

#pragma once
#include <opencv2/opencv.hpp>
#include <time.h>
#include "afxwin.h"
using namespace std;
using namespace cv;

// CMFCApplication4Dlg 대화 상자
class CMFCApplication4Dlg : public CDialogEx
{
private:
	CRect getCanvasRect() const;
// 생성입니다.
public:
	CMFCApplication4Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	Mat m_SelectedRegion;
	Mat src;
	Mat aa;
// 대화 상자 데이터입니다.
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };
	CPoint rect_start_pos;
	Mat a;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.
	
public:
	void DisplayImage(int IDC_PICTURE_TARGET, Mat targetMat);
	void ClientToImageCoordinates(CPoint& point);
	
// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
