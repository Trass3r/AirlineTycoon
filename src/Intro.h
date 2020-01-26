// Intro.cpp : Der Render-Intro

/////////////////////////////////////////////////////////////////////////////
// CIntro window

class CIntro : public CStdRaum
{
// Construction
public:
	CIntro(BOOL bHandy, SLONG PlayerNum);

// Attributes
public:
    smk          pSmack;
    char         State;
    SBBM         Bitmap;

    SBBM         FadeFrom;
    SBBM         FadeTo;
    bool         bWasIntroPlayed;

    GfxLib      *pRoomLib;               //Library f�r den Raum

    SLONG        FrameNum;
    SLONG        FadeCount;
    DWORD        FrameNext;
    ULONG        Width;
    ULONG        Height;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIntro)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CIntro() override;

	// Generated message map functions
public:
	//{{AFX_MSG(CIntro)
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
