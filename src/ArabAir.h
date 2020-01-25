//============================================================================================
// ArabAir.h : Der Schalter und das Hinterzimmer von ArabAir!
//============================================================================================

class CArabAir : public CStdRaum
{
// Construction
public:
	CArabAir(BOOL bHandy, ULONG PlayerNum);

// Data
public:
   CSmackerPerson SP_Araber;
   CAnimation     FunkelAnim;
   SBBM           GloveBm;

   SBFX           StartupFX;
   SBFX           RadioFX;

   SB_CFont       FontBankBlack;
   SB_CFont       FontBankRed;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CArabAir)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CArabAir() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(CArabAir)
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
