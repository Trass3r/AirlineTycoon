//============================================================================================
// Rushmore.h : Der Nasa-Shop
//============================================================================================

class CRushmore : public CStdRaum
{
// Construction
public:
	CRushmore(BOOL bHandy, ULONG PlayerNum);

   SBBMS   LogoBms;
   SBBM    TextBm;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRushmore)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CRushmore() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(CRushmore)
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
