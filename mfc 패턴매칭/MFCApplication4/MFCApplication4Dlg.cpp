
// MFCApplication4Dlg.cpp : ���� ����
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


// CMFCApplication4Dlg �޽��� ó����

BOOL CMFCApplication4Dlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFCApplication4Dlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication4Dlg::OnBnClickedOk()
{

	char szFilter[] = "Image (*.BMP, *.GIF, *.JPG, *.PNG) | *.BMP;*.GIF;*.JPG;*.PNG;*.bmp;*.gif;*.jpg;*.png | All Files(*.*)|*.*||";//���� Ȯ���� Ȯ���� ����
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, AfxGetMainWnd());//��ȭ ���� ����
	if (dlg.DoModal() == IDOK)//����ڰ� ��ư�� Ŭ������ ��
	{
		CString cstrImgPath = dlg.GetPathName();
		//AfxMessageBox(cstrImgPath);
		src = imread(string(cstrImgPath));
		DisplayImage(IDC_PIC1, src);
	}//���� ��θ� ��� ����


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
	IplImage* targetIplImage = new IplImage(targetMat);//��ü�� ��ȯ
	if (targetIplImage != nullptr){
		CWnd* pWnd_ImageTraget = GetDlgItem(IDC_PIC1);
		CClientDC dcImageTraget(pWnd_ImageTraget);
		RECT rcImageTraget;
		pWnd_ImageTraget->GetClientRect(&rcImageTraget);//CWND �� CClinetDC����

		BITMAPINFO bitmapInfo;
		memset(&bitmapInfo, 0, sizeof(bitmapInfo));
		bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bitmapInfo.bmiHeader.biPlanes = 1;
		bitmapInfo.bmiHeader.biCompression = BI_RGB;
		bitmapInfo.bmiHeader.biWidth = targetIplImage->width;
		bitmapInfo.bmiHeader.biHeight = -targetIplImage->height;//��Ʈ�� ���� �ʱ�ȭ

		IplImage *tempImage = nullptr;

		if (targetIplImage->nChannels == 1) 
		{
			tempImage = cvCreateImage(cvSize(targetIplImage->width, targetIplImage->height), IPL_DEPTH_8U, 3);
			cvCvtColor(targetIplImage, tempImage, CV_GRAY2BGR);
		}
		else if (targetIplImage->nChannels == 3)
		{
			tempImage = cvCloneImage(targetIplImage);
		}//�̹��� ä�μ��� ���� ó���� ���� ����� BGR�� �÷��� �״��

		bitmapInfo.bmiHeader.biBitCount = tempImage->depth * tempImage->nChannels;

		dcImageTraget.SetStretchBltMode(COLORONCOLOR);
		::StretchDIBits(dcImageTraget.GetSafeHdc(), rcImageTraget.left, rcImageTraget.top, rcImageTraget.right, rcImageTraget.bottom,
			0, 0, tempImage->width, tempImage->height, tempImage->imageData, &bitmapInfo, DIB_RGB_COLORS, SRCCOPY);//�̹����� ��ȭ ������ ��Ʈ�ѿ� ǥ��

		cvReleaseImage(&tempImage);// �������� �Ҵ�� �޸𸮸� ����
	}
}


void CMFCApplication4Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{

	rect_start_pos = point;
	ClientToImageCoordinates(rect_start_pos);  // ȭ�� ��ǥ�� �̹��� ��ǥ�� ��ȯ
	CDialogEx::OnLButtonDown(nFlags, point);

}

CRect CMFCApplication4Dlg::getCanvasRect() const {
	CWnd* canvas = GetDlgItem(IDC_PIC1);
	CRect rect;
	canvas->GetWindowRect(rect);
	ScreenToClient(rect);
	// �ٸ� �����̳� ����� �ʿ��� ��� ���⿡ �߰��ϼ���.
	return rect;
}

void CMFCApplication4Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	
		CString str;
		CClientDC dc(this); // DC ����
		CRect rectPic;
		GetDlgItem(IDC_PIC1)->GetWindowRect(&rectPic);
		ScreenToClient(&rectPic);

		SelectObject(dc, GetStockObject(NULL_BRUSH)); // ���� ������ ������ �׷��ֱ� ���� NULL �귯���� �����.
		ClientToImageCoordinates(point);  // ȭ�� ��ǥ�� �̹��� ��ǥ�� ��ȯ

		int centerX = (rect_start_pos.x + point.x) / 2 - (rectPic.left + rectPic.right) / 2;
		int centerY = (rect_start_pos.y + point.y) / 2 - (rectPic.top + rectPic.bottom) / 2;

		int width = abs(point.x - rect_start_pos.x);
		int height = abs(point.y - rect_start_pos.y);

		dc.Rectangle(rect_start_pos.x, rect_start_pos.y, point.x, point.y);

		// �̹������� ������ ������ �����ͼ� ǥ��
		aa = src(Rect(Point(rect_start_pos.x, rect_start_pos.y), Point(point.x, point.y)));

		string dd = "newjeans1.jpg"; // ���� �̸��� �ʿ信 ���� �����ϼ���.
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

	// Picture Control�� ���߾� ��ǥ�� ����մϴ�.
	int centerX = rectPic.left + rectPic.Width() / 2;
	int centerY = rectPic.top + rectPic.Height() / 2;

	// ���콺 ��ġ�� Picture Control�� ���߾��� (0,0)���� �ϴ� ��ǥ��� ��ȯ�մϴ�.
	int relativeX = point.x - centerX;
	int relativeY = centerY - point.y;  // Y ���� �� ������ ����̹Ƿ� ��ȣ�� �ٲ��ݴϴ�.

	// ��ȯ�� ��ǥ�� ���ڿ��� ��ȯ�մϴ�.
	CString str;
	str.Format(_T("(%d, %d)"), relativeX, relativeY);

	// IDC_EDIT7�� ����ִ� ����Ʈ ��Ʈ���� ID�� �����Ͽ����ϴ�.
	// ������ ����ϴ� ����Ʈ ��Ʈ���� ID�� �°� �����ϼ���.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCApplication4Dlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCApplication4Dlg::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCApplication4Dlg::OnEnChangeEdit4()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMFCApplication4Dlg::OnEnChangeEdit5()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
