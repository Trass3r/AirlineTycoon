// Outro.cpp : Der Render-Outro

/////////////////////////////////////////////////////////////////////////////
// COutro window

class COutro : public CStdRaum
{
// Construction
public:
	COutro(BOOL bHandy, SLONG PlayerNum, CString SmackName);

// Attributes
public:
    smk          pSmack;
    char         State;
    SBBM         Bitmap;

    SLONG        FrameNum;
    DWORD        FrameNext;
    ULONG        Width;
    ULONG        Height;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutro)
	//}}AFX_VIRTUAL

// Implementation
public:
	~COutro() override;

	// Generated message map functions
public:
	//{{AFX_MSG(COutro)
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	BOOL OnSetCursor(void* pWnd, UINT nHitTest, UINT message) override;
	void OnMouseMove(UINT nFlags, CPoint point) override;
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()

private:
	SDL_AudioDeviceID audioDevice;
};

/////////////////////////////////////////////////////////////////////////////
