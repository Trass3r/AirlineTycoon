//============================================================================================
// RouteBox.h : Der Schalter und das Hinterzimmer von RouteBox!
//============================================================================================

class CRouteBox : public CStdRaum
{
// Construction
public:
	CRouteBox(BOOL bHandy, ULONG PlayerNum);

// Data
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRouteBox)
	//}}AFX_VIRTUAL

   CDataTable Table;

   SLONG      DisplayPlayer;           //Bits 0-3 sind belegt
   SLONG      Filter;

   SBBM       ListBm;                  //Der Text in der Liste
   SBBM       TipBm;                   //Die Tip-Bitmap mit Text
   SBBM       MapBm;                   //Die Karte
   SBBM       HakenBm;
   SBBM       HereBm;
   SBBM       NoPaperBm;
   SBBMS      PlayerBms;
   SBBMS      EckenBms;
   SBBMS      FilterBms;
             
   SLONG      RoutePage;
   SLONG      RoutePageMax;

   SLONG      CurrentTip;
   SLONG      CurrentTipIndex;         //Index im Table-Array

   SLONG      LastTip;

   BUFFER<BOOL> IsBuyable;

// Implementation
public:
	~CRouteBox() override;

   void RepaintList (void);
   void RepaintTip (void);
   void RepaintMap (void);
   void UpdateDataTable (void);

	// Generated message map functions
protected:
	//{{AFX_MSG(CRouteBox)
	void OnLButtonDown(UINT nFlags, CPoint point) override;
   void OnLButtonDblClk(UINT nFlags, CPoint point) override;
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
