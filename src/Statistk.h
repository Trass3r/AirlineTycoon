
//============================================================================================
// Statistk.h : Der Statistik-Screen
//============================================================================================

class CStatButton
{
   public:
      SLONG  Id;                       //Frei w�hlbar, aber bitte immer eindeutig
      SLONG  HelpId;                   //ToolTipID
      CRect  HotArea;                  //MouseArea, wo der Button gehighlighted wird
      XY     BitmapOffset;             //Hierhin wird die Button-Bitmap geblittet
      XY    *BitmapOffset2;            //Referenzm�glichkeit f�r bewegte Buttons
      SBBM  *BitmapNormal;             //Normale Bitmap oder NULL
      SBBM  *BitmapHi;                 //Bitmap f�rs Highlight oder NULL
      SBBM  *BitmapClicked;            //Bitmap f�rs Geclickte oder NULL
      SBBM  *BitmapSuperHi;            //Nur f�r Toggle-Buttons: Highlight, wenn geklickt
      BOOL   IsToggle;                 //Ist es ein Toggle-Button?
      DWORD  LastClicked;              //Wann wurde er zum letzten Mal geklickt (intern)

   public:
      void ReSize (SLONG Id, SLONG  HelpId, CRect HotArea, XY BitmapOffset, XY *BitmapOffset2, SBBM *BitmapNormal, SBBM *BitmapHi, SBBM *BitmapClicked, SBBM *BitmapSuperHi, BOOL IsToggle);
};

#define	MAX_GROUP			3				// Anzahl der Gruppen
#define	MAX_ITEMS			16				// Anzahl der Eintr�ge je Gruppe
#define	LINE_DISTANCE		20				// Abstand der Zeilen

#define	TYP_LINEFEED		0				// Leerzeile
#define	TYP_GROUP			1				// Gruppe
#define	TYP_SUM_CURR		2				// Summe einer Gruppe
#define	TYP_SUM_CURR_N		3				// Summe einer Gruppe (-)
#define	TYP_SUM_DIFF		4				// Differenz der Summen
#define  TYP_SHAREVALUE		5				// Wert aller Aktien zusammen

#define	TYP_VALUE			20				// Normale Zahl
#define	TYP_CURRENCY		21				// W�hrung
#define	TYP_PERCENT    	22				// Prozent
#define	TYP_SINGLE_PERCENT 23		   // Prozent, aber nicht in Abh�ngigkeit von der Vorvariable


typedef struct tagItem
{
	bool	visible;
	short	textId;
	short	define;
	short	typOfItem;

} ITEM;


class CStatistik : public CStdRaum
{
// Construction
public:
	CStatistik(BOOL bHandy, ULONG PlayerNum);

   BUFFER<CStatButton> StatButtons;    //Die Statistik Buttons

   SBBM     HighlightBar;              //Der helle Balken f�r die optische Auswahl
   SBBM     TopSaver;                  //Verhindert, da� der obere Rand von den Zoomicons �berschrien wird

   SBBM     DropDownBackgroundBm;      //Die Hintergrundbitmap
   SBBM     DropDownBm;                //Die Hintergrundbitmap mit Linien drauf
   SBBMS    UpDownArrows;              //Die Buttons zum runter/raufscrollen
                                      
   SBBM     TextTableBm;               //Die Bitmap mit den Texten (kann von der Drop-Down Liste �berdeckt werden)
                                      
   SBBMS    LupeLogoBms;               //Die Lupe mit dem Firmenlogo
   SBBMS    LupeZoomBms;               //Die Lupe mit +/s
   SBBMS    ButtonGeldBms;             //Die Buttons mit dem Geld
   SBBMS    ButtonRouteBms;            //Die Buttons mit der Route
                                      
   SBBMS    ExitBms;                   //Das Exit-Schild
   SBBMS    LogoBms;                   //Die Vier gro�en Spielerlogos in 3 varianten
	SBBMS		PobelBms;

   XY       DropDownPos;
   SLONG    DropDownSpeed;

	SBBM		Haeckchen;

   SB_CFont StatFonts[5];             //0=Schwarz, 1-4=Farben der Spieler


	// Diese Werte am besten in der Registry
	// speichern.
	bool		_fGraphVisible;							// true -> Der Graph ist sichtbar, ansonsten die schn�den Zahlen
	bool		_playerMask[4];							// Diese Spieler wurden zur Ansicht ausgew�hlt
	BYTE		_group;										// Die angew�hlte Gruppe (*0=Finanzen, 1=?, 2=?)
	long		_days;										// Anzahl der darzustellenden Tage
	long		_newDays;									// F�r eine Animation
	ITEM		_iArray[MAX_GROUP][MAX_ITEMS];		// Merkt sich f�r jede Gruppe welche Eintr�ge selektiert sind.

	// Tempor�re Werte
	short		_selectedItem;
	short		_oldSelectedItem;
	double	_yAxis;
	double	_xGraph;
	double	_yGraph;

	bool		_fRepaint;

// Attributes
public:

// Operations
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatistik)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CStatistik() override;

	// Generated message map functions
protected:
   void	 RepaintGraphWindow (void);
	void	 CalcGraph (void);

   void RepaintTextWindow (void);

	//{{AFX_MSG(CStatistik)
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};
