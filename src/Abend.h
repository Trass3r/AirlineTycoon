//============================================================================================
// Abend.cpp : Die Feierabendsequenz (Header File)
//============================================================================================

class CAbend : public CStdRaum
{
// Construction
public:
	CAbend (BOOL bHandy, ULONG PlayerNum);

// Attributes
public:
   CWait Waiting;
   BOOL  Room;                //1=Uhr; 2=Flughafen
   SLONG Ticker;
   SLONG State;
   XY    PlayerPos[4];
   DWORD LastTime;
   SBBM  AirportBm;
   SBBM  NightBm;
   SBFX  StartupFX;
   SLONG LastHour;

   SLONG StartSeason;        //In dieser Jahreszeit haben wir die Nacht begonnen

// Operations
public:
   void DoOneStep (void);
   void ReloadBitmaps (void);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAbend)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CAbend() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(CAbend)
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) override;
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
