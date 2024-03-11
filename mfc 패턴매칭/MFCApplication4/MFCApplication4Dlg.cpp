
// MFCApplication4Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"
#include <time.h>


#ifdef _DEBUGt
#define new DEBUG_NEW
#endif

using namespace std;
using namespace cv;
CRect rectPic;
CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication4Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, aaa);
	DDX_Control(pDX, IDC_EDIT2, bbb);
	DDX_Control(pDX, IDC_EDIT3, ccc);
	DDX_Control(pDX, IDC_EDIT4, ddd);
	DDX_Control(pDX, IDC_EDIT5, eee);
}

BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication4Dlg::OnBnClickedOk)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()

	ON_STN_CLICKED(IDC_PIC1, &CMFCApplication4Dlg::OnStnClickedPic1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication4Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication4Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication4Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication4Dlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CMFCApplication4Dlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CMFCApplication4Dlg::OnEnChangeEdit5)
END_MESSAGE_MAP()


// CMFCApplication4Dlg 메시지 처리기

BOOL CMFCApplication4Dlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication4Dlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication4Dlg::OnBnClickedOk()
{

	char szFilter[] = "Image (*.BMP, *.GIF, *.JPG, *.PNG) | *.BMP;*.GIF;*.JPG;*.PNG;*.bmp;*.gif;*.jpg;*.png | All Files(*.*)|*.*||";//파일 확장자 확인후 실행
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, AfxGetMainWnd());//대화 상자 생성
	if (dlg.DoModal() == IDOK)//사용자가 버튼을 클릭했을 때
	{
		CString cstrImgPath = dlg.GetPathName();
		//AfxMessageBox(cstrImgPath);
		src = imread(string(cstrImgPath));
		DisplayImage(IDC_PIC1, src);
	}//파일 경로를 얻고 읽음


	//string templateImagePath = "newjeans1.jpg";
	//Mat templateImage = imread(templateImagePath, IMREAD_COLOR);

	//if (templateImage.empty())
	//{
	//	AfxMessageBox(_T("Error loading template image!"));
	//	return;
	//}


	//Mat result;
	//matchTemplate(src, templateImage, result, TM_CCOEFF_NORMED);

	//
	//double minVal, maxVal;
	//Point minLoc, maxLoc;
	//minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);


	//Rect matchRect(maxLoc, Point(maxLoc.x + templateImage.cols, maxLoc.y + templateImage.rows));
	//rectangle(src, matchRect, Scalar(0, 255, 0), 2); // Green rectangle

	//
	//DisplayImage(IDC_PIC1, src);
}

void CMFCApplication4Dlg::DisplayImage(int IDC_PICTURE_TARGET, Mat targetMat)
{
	IplImage* targetIplImage = new IplImage(targetMat);//객체를 변환
	if (targetIplImage != nullptr){
		CWnd* pWnd_ImageTraget = GetDlgItem(IDC_PIC1);
		CClientDC dcImageTraget(pWnd_ImageTraget);
		RECT rcImageTraget;
		pWnd_ImageTraget->GetClientRect(&rcImageTraget);//CWND 및 CClinetDC설정

		BITMAPINFO bitmapInfo;
		memset(&bitmapInfo, 0, sizeof(bitmapInfo));
		bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bitmapInfo.bmiHeader.biPlanes = 1;
		bitmapInfo.bmiHeader.biCompression = BI_RGB;
		bitmapInfo.bmiHeader.biWidth = targetIplImage->width;
		bitmapInfo.bmiHeader.biHeight = -targetIplImage->height;//비트맵 정보 초기화

		IplImage *tempImage = nullptr;

		if (targetIplImage->nChannels == 1) 
		{
			tempImage = cvCreateImage(cvSize(targetIplImage->width, targetIplImage->height), IPL_DEPTH_8U, 3);
			cvCvtColor(targetIplImage, tempImage, CV_GRAY2BGR);
		}
		else if (targetIplImage->nChannels == 3)
		{
			tempImage = cvCloneImage(targetIplImage);
		}//이미지 채널수에 따른 처리를 수행 흑백은 BGR로 컬러는 그대로

		bitmapInfo.bmiHeader.biBitCount = tempImage->depth * tempImage->nChannels;

		dcImageTraget.SetStretchBltMode(COLORONCOLOR);
		::StretchDIBits(dcImageTraget.GetSafeHdc(), rcImageTraget.left, rcImageTraget.top, rcImageTraget.right, rcImageTraget.bottom,
			0, 0, tempImage->width, tempImage->height, tempImage->imageData, &bitmapInfo, DIB_RGB_COLORS, SRCCOPY);//이미지를 대화 상자의 컨트롤에 표시

		cvReleaseImage(&tempImage);// 동적으로 할당된 메모리를 해제
	}
}


void CMFCApplication4Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{

	rect_start_pos = point;
	ClientToImageCoordinates(rect_start_pos);  // 화면 좌표를 이미지 좌표로 변환
	CDialogEx::OnLButtonDown(nFlags, point);

}

CRect CMFCApplication4Dlg::getCanvasRect() const {
	CWnd* canvas = GetDlgItem(IDC_PIC1);
	CRect rect;
	canvas->GetWindowRect(rect);
	ScreenToClient(rect);
	// 다른 조정이나 계산이 필요한 경우 여기에 추가하세요.
	return rect;
}

void CMFCApplication4Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	
		CString str;
		CClientDC dc(this); // DC 생성
		CRect rectPic;
		GetDlgItem(IDC_PIC1)->GetWindowRect(&rectPic);
		ScreenToClient(&rectPic);

		SelectObject(dc, GetStockObject(NULL_BRUSH)); // 안이 투명한 도형을 그려주기 위해 NULL 브러쉬를 만든다.
		ClientToImageCoordinates(point);  // 화면 좌표를 이미지 좌표로 변환

		int centerX = (rect_start_pos.x + point.x) / 2 - (rectPic.left + rectPic.right) / 2;
		int centerY = (rect_start_pos.y + point.y) / 2 - (rectPic.top + rectPic.bottom) / 2;

		int width = abs(point.x - rect_start_pos.x);
		int height = abs(point.y - rect_start_pos.y);

		dc.Rectangle(rect_start_pos.x, rect_start_pos.y, point.x, point.y);

		// 이미지에서 선택한 영역을 가져와서 표시
		aa = src(Rect(Point(rect_start_pos.x, rect_start_pos.y), Point(point.x, point.y)));

		string dd = "newjeans1.jpg"; // 파일 이름을 필요에 따라 변경하세요.
		imwrite(dd, aa);
		imshow("aa", aa);

		CDialogEx::OnLButtonUp(nFlags, point);
		str.Format(_T("%d"), centerX);
		GetDlgItem(IDC_EDIT1)->SetWindowText(str);

		str.Format(_T("%d"), -centerY);
		GetDlgItem(IDC_EDIT2)->SetWindowText(str);

		str.Format(_T("%d"), width);
		GetDlgItem(IDC_EDIT3)->SetWindowText(str);

		str.Format(_T("%d"), height);
		GetDlgItem(IDC_EDIT4)->SetWindowText(str);
	
}
void CMFCApplication4Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CRect rectPic;
	GetDlgItem(IDC_PIC1)->GetWindowRect(&rectPic);
	ScreenToClient(&rectPic);

	// Picture Control의 정중앙 좌표를 계산합니다.
	int centerX = rectPic.left + rectPic.Width() / 2;
	int centerY = rectPic.top + rectPic.Height() / 2;

	// 마우스 위치를 Picture Control의 정중앙을 (0,0)으로 하는 좌표계로 변환합니다.
	int relativeX = point.x - centerX;
	int relativeY = centerY - point.y;  // Y 축은 위 방향이 양수이므로 부호를 바꿔줍니다.

	// 변환된 좌표를 문자열로 변환합니다.
	CString str;
	str.Format(_T("(%d, %d)"), relativeX, relativeY);

	// IDC_EDIT7은 비어있는 에디트 컨트롤의 ID로 가정하였습니다.
	// 실제로 사용하는 에디트 컨트롤의 ID에 맞게 수정하세요.
	GetDlgItem(IDC_EDIT5)->SetWindowText(str);
	CDialogEx::OnMouseMove(nFlags, point);
}

void CMFCApplication4Dlg::ClientToImageCoordinates(CPoint& point)
{
	CRect rectClient;
	GetClientRect(&rectClient);

	point.x = static_cast<int>(point.x * static_cast<double>(src.cols) / static_cast<double>(rectClient.Width()));
	point.y = static_cast<int>(point.y * static_cast<double>(src.rows) / static_cast<double>(rectClient.Height()));
}



void CMFCApplication4Dlg::OnStnClickedPic1()
{
	
}


void CMFCApplication4Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	string templateImagePath = "newjeans1.jpg";
	Mat templateImage = imread(templateImagePath, IMREAD_COLOR);

	if (templateImage.empty())
	{
		AfxMessageBox(_T("Error loading template image!"));
		return;
	}


	Mat result;
	matchTemplate(src, templateImage, result, TM_CCOEFF_NORMED);


	double minVal, maxVal;
	Point minLoc, maxLoc;
	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);


	Rect matchRect(maxLoc, Point(maxLoc.x + templateImage.cols, maxLoc.y + templateImage.rows));
	rectangle(src, matchRect, Scalar(0, 255, 0), 2); // Green rectangle


	DisplayImage(IDC_PIC1, src);
}


void CMFCApplication4Dlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication4Dlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication4Dlg::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication4Dlg::OnEnChangeEdit4()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication4Dlg::OnEnChangeEdit5()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
