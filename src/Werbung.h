//============================================================================================
// Werbung.h : Die Werbeagentur!
//============================================================================================

class CWerbung : public CStdRaum
{
// Construction
public:
	CWerbung(BOOL qHandy, ULONG PlayerNum);

// Operations
public:
   SBBM        TipBm;               //Fenster für Flugzeug-Details
   SBBM        DiskBm;
   SBBM        NoSaboBm;
   SLONG       CurrentTip;          //Dieser Tip wird gerade angezeigt

   SBFX        CoffeeFx;
   SBFX        SpratzelFx;

   SBBMS       JahreszeitBms;

   CAnimation  BoyAnim;
   CAnimation  ScreenAnim;
   CAnimation  KaffeeAnim;
   CAnimation  SpratzelAnim;

   CSmackerPerson SP_Mann;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWerbung)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CWerbung() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(CWerbung)
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
