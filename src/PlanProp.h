//============================================================================================
// PlaneProps.h : Die Eigenschaften von einem Flugzeug
//============================================================================================

class CPlaneProps : public CStdRaum
{
// Construction
public:
	CPlaneProps(BOOL bHandy, ULONG PlayerNum);

// Data
public:
   SBBM       Back1, Back2;
   SBBM       MenuMaskBm;
   SBBM       BadgeBm;

   SLONG      ActivePage;
   SLONG      ActiveDir;

   SBBMS      Prozente;

   SBBMS      Floors;
   SBBMS      Seats;
   SBBMS      Food;
   SBBMS      SosBms;
   SBBMS      ReifenBms;
   SBBMS      CockpitBms;
   SBBMS      TurbinenBms;

   SBBMS      CursorBms;
   SBBMS      StarBms;
   SBBMS      MenuBms;
   SBBMS      StewardessBms;
   SBBMS      DigitBms;

   CDataTable PlaneDataTable;
   SLONG      PlaneIndex;

   SLONG      BlinkArrowsTimer;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaneProps)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CPlaneProps() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(CPlaneProps)
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
   void OnLButtonDblClk(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
