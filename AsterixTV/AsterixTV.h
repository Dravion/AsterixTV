
// AsterixTV.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CAsterixTVApp:
// Siehe AsterixTV.cpp für die Implementierung dieser Klasse
//

class CAsterixTVApp : public CWinApp
{
public:
	CAsterixTVApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CAsterixTVApp theApp;