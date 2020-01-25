// HallDiskMenu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// HallDiskMenu window

class HallDiskMenu : public CStdRaum
{
// Construction
public:
	HallDiskMenu(BOOL bHandy, SLONG PlayerNum);

// Attributes
public:
   SBBM           MenuBm;
   GfxLib        *pMenuLib;
   BOOL           bFiles[10*10];

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(HallDiskMenu)
	//}}AFX_VIRTUAL

// Implementation
public:
	~HallDiskMenu() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(HallDiskMenu)
	void OnPaint() override;
	virtual void OnClose();
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	BOOL OnSetCursor(void* pWnd, UINT nHitTest, UINT message) override;
	void OnMouseMove(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
