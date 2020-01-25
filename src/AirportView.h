// AirportView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AirportView window

class AirportView : public CStdRaum
{
// Construction
public:
	AirportView(BOOL bHandy, ULONG PlayerNum);

//Attributes:
public:
   BOOL           LButtonState;        //Status des linken Mausknopfes
   ULONG          EditObject;          //Das Objekt, was gerade am Cursor klebt
   ULONG          EditObject2;         //zweite Objekt (für Links)
   ULONG          UnderCursor;         //Das Objekt, über dem der Cursor gerade ist
	SLONG			   PersonsToAdd;		   //Zahl Personen, die noch zum Test kommen sollen

// Operations
public:
   void AnnouceTipDataUpdate (SLONG TipType);
   void ReloadBitmaps (void);          //Lädt alle Bitmaps erneut
   void FocusCameraOnPos (XY Pos, BOOL Speed);     //Setzt die aktuelle Kameraposition
   void CenterCameraOnPlayer (void);
   void MoveCamera (void);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AirportView)
	//}}AFX_VIRTUAL

// Implementation
public:
	~AirportView() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(AirportView)
	void OnPaint() override;
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) override;
	virtual void OnToggleEditor();
	void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	virtual void OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnLButtonDblClk(UINT nFlags, CPoint point) override;
	void OnLButtonUp(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
