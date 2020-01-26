// NewGamePopup.h : header file
//
#include "sblib\include\SbLib.h"
#include "sblib\include\network.h"

/////////////////////////////////////////////////////////////////////////////
// NewGamePopup window

class NewGamePopup : public CStdRaum
{
// Construction
public:
	NewGamePopup(BOOL bHandy, SLONG PlayerNum);

// Attributes
private:
   BOOL            TimerFailure;
   UBYTE           PageNum;       //Seite 1 oder 2
   SLONG           PageSub;       //Sub-Id f�r die Seite
   SLONG           bad;
   KLACKER         KlackerTafel;  //Die Tafel auf der alles angezeigt wird
   ULONG           PlayerReadyAt;
   ULONG           UnselectedNetworkIDs[4];

   SDL_TimerID     TimerId;
   SB_CFont        VersionFont;

   SLONG           CursorX, CursorY; //Der blinkende Eingabecursor; -1 = kein Cursor sichtbar
   UBYTE           BlinkState;
   SBBMS           PlayerBms;
   SBBM            HakenBm;
   SLONG           Selection;

   BOOL            NamesOK;       //Sind alle Namen eindeutig?

   SBFX            ClickFx;

   SBList<SBStr>           *pNetworkSessions;
   SBList<SBStr>           *pNetworkConnections;
   SBList<SBNetworkPlayer> *pNetworkPlayers;

   ULONG                    PlayerID;
   bool                     bThisIsSessionMaster;

   SBStr                    NetworkConnection;
   static SBStr             NetworkSession;

   long NetMediumCount;
   long NetMediumMapper[32];

// Operations
public:
   void Konstruktor (BOOL bHandy, SLONG PlayerNum);
   void RefreshKlackerField (void);
   void CheckNames (void);
   void PushNames (void);
   void PushName (SLONG n);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(NewGamePopup)
	//}}AFX_VIRTUAL

// Implementation
public:
	~NewGamePopup() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(NewGamePopup)
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
