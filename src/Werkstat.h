//============================================================================================
// Werkstat.h : Der Schalter und das Hinterzimmer von ArabAir!
//============================================================================================

class CWerkstatt : public CStdRaum
{
// Construction
public:
	CWerkstatt(BOOL bHandy, ULONG PlayerNum);

// Operations
public:
   SBBM                    OilCanBm;
   SBBM                    DoorBm;

   SBFX                    SawFx;

   SLONG                   CurrentTip;          //Dieser Tip wird gerade angezeigt

   CAnimation              SoudAnim;
   CAnimation              FlameAnim;
   CAnimation              LightAnim;

   SLONG                   KommVar;

   CSmackerPerson          SP_Mann;
   CSmackerPerson          SP_Hund;
   CSmackerPerson          SP_Wer;
   CSmackerPerson          SP_Bombe;
   CSmackerPerson          SP_Asche;
   CSmackerPerson          SP_Schleim;
   CSmackerPerson          SP_Blase[5];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWerkstatt)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CWerkstatt() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(CWerkstatt)
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
