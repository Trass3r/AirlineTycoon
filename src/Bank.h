//============================================================================================
// Bank.h : Der Bankraum (Header File)
//============================================================================================

class Bank : public CStdRaum
{
// Construction
public:
	Bank(BOOL bHandy, ULONG PlayerNum);

   SBBM           MoneyBm;
        
   CSmackerPerson SP_Modem;
   
   CAnimation     MonitorAnim;
   CAnimation     KameraAnim;
   SLONG          CatchFly;
   SLONG          FlyCaught;

   SB_CFont       FontBankBlack;
   SB_CFont       FontBankRed;

   CSmackerPerson SP_Mann;
   CSmackerPerson SP_Frau;
   CSmackerPerson SP_Pflanze;
   CSmackerPerson SP_Fliege;

// Attributes
public:
   TEXT_STYLE StyleAktie;     //Angestellter f�r Aktie
   TEXT_STYLE StyleKredit;    //Angestellter f�r Kredit
   TEXT_STYLE StyleAuszug;    //Style f�r den Kontoauszug
   SLONG      CurrentText;    //Nummer des aktuellen Dialogs
   SLONG      CurrentValue;   //Betrag �ber den gerade geredet wird..
   SBBM       TipBm;          //Fenster f�r Flugzeug-Tips
   SLONG      CurrentAktie;   //�ber dieses Flugzeug wir geredet
   SLONG      CurrentTip;     //Dieser Tip wird gerade angezeigt
   SLONG      KontoType;      //-1=Kein Men� offen; 1=Kredit aufnehmen; 2=Tilgen
   SBBM       ZettelBm;
   GfxLib    *pMenuLib;

// Operations
public:
   void ReloadBitmaps (void);
   void PaintKontoBm (SBBM &TipBm, SLONG KontoType);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Bank)
	//}}AFX_VIRTUAL

// Implementation
public:
	~Bank() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(Bank)
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};