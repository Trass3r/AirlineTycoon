// AskBrick.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AskBrick window

class AskBrick : public CStdRaum
{
// Construction
public:
	AskBrick(BOOL bHandy, SLONG PlayerNum, ULONG Group, ULONG *rc1);

// Attributes
public:
   SBBM           AskBrickBm;
   GfxLib        *pMenuLib;

private:
   ULONG Group;
   ULONG *rc1;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AskBrick)
	//}}AFX_VIRTUAL

// Implementation
public:
	~AskBrick() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(AskBrick)
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) override;
	virtual void OnClose();
	BOOL OnSetCursor(void* pWnd, UINT nHitTest, UINT message) override;
	void OnMouseMove(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
