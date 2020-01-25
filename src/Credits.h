// CCredits.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCredits window

class CCredits : public CStdRaum
{
// Construction
public:
	CCredits(BOOL bHandy, SLONG PlayerNum);

// Attributes
private:
   GfxLib         *pGLibCredits;
   SBBM            Background;
   SBBM            Left, Right;
   SBBM            TextLines[25];
   BOOL            TimerFailure;
   SLONG           ScrollPos;
   SLONG           LastTime;
   TEXT_STYLE      StyleCredits;

// Operations
public:
   void ReloadBitmap (void);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCredits)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CCredits() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(CCredits)
	void OnPaint() override;
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnTimer(UINT nIDEvent) override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) override;
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) override;
	BOOL OnSetCursor(void* pWnd, UINT nHitTest, UINT message) override;
	void OnMouseMove(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
