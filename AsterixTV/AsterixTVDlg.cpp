
// AsterixTVDlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "AsterixTV.h"
#include "AsterixTVDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAsterixTVDlg-Dialogfeld



CAsterixTVDlg::CAsterixTVDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ASTERIXTV_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAsterixTVDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAsterixTVDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAsterixTVDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAsterixTVDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAsterixTVDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAsterixTVDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CAsterixTVDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CAsterixTVDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDOK, &CAsterixTVDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAsterixTVDlg-Meldungshandler

BOOL CAsterixTVDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
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

	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen

	CRect rect;
	CWnd *pWnd = this;
	pWnd->GetWindowRect(&rect);
	this->ScreenToClient(&rect);
	this->MoveWindow(120, 120, rect.Width(), rect.Height());
	this->SetBackgroundColor(RGB(255, 255, 255));

	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

void CAsterixTVDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen.  Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CAsterixTVDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CAsterixTVDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAsterixTVDlg::OnBnClickedButton1()
{
	ShellExecute(nullptr, L"open", L"http://www.daserste.de/live/index.html#", nullptr, nullptr, SW_SHOWNORMAL);
}


void CAsterixTVDlg::OnBnClickedButton2()
{
	ShellExecute(nullptr, L"open", L"http://www.tagesschau.de/multimedia/livestreams/", nullptr, nullptr, SW_SHOWNORMAL);
}


void CAsterixTVDlg::OnBnClickedButton3()
{
	ShellExecute(nullptr, L"open", L"http://www.arte.tv/guide/de/live", nullptr, nullptr, SW_SHOWNORMAL);

}


void CAsterixTVDlg::OnBnClickedButton4()
{
	ShellExecute(nullptr, L"open", L"http://www.n24.de/n24/Mediathek/Live/", nullptr, nullptr, SW_SHOWNORMAL);

}


void CAsterixTVDlg::OnBnClickedButton5()
{
	ShellExecute(nullptr, L"open", L"http://www.phoenix.de/livestream/", nullptr, nullptr, SW_SHOWNORMAL);
}


void CAsterixTVDlg::OnBnClickedButton6()
{
	ShellExecute(nullptr, L"open", L"http://www.zdf.de/ZDFmediathek/beitrag/live/1822600/Das-ZDF-im-Livestream#/beitrag/livevideo/1822600/Das-ZDF-im-Livestream", nullptr, nullptr, SW_SHOWNORMAL);


}


void CAsterixTVDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
