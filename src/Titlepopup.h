// TitlePopup.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TitlePopup window

class TitlePopup : public CStdRaum
{
// Construction
public:
	TitlePopup(BOOL bHandy, SLONG PlayerNum);

// Attributes
private:
   GfxLib    *pRoomLib;             //Library f�r den Raum;
   SBBM TitleBitmap;
   SBBM HeadlineBm;
   BUFFER<SBBMS> LineBms;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TitlePopup)
	//}}AFX_VIRTUAL

// Implementation
public:
	~TitlePopup() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(TitlePopup)
	void OnPaint() override;
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
