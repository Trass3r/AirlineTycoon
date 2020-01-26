//============================================================================================
// Laptop.h : header file
//============================================================================================
class CLaptop : public CPlaner
{
   //Construction:
   public:
	   CLaptop(BOOL bHandy, ULONG PlayerNum);

   //Attributes:
   public:
      //Bitmaps:
      SBBMS   MonitorEdges;

      CSmackerPerson SP_Antivir;
      CSmackerPerson SP_Lampe;
      SLONG          KommVarLampe;

      CSmackerPerson SP_Buttons[6];
      SLONG          KommVarButtons[6];
      BOOL           HasVirus;

      //Die Ikonen & Bitmaps:
      GfxLib *pGLibIcons[6];
      SBBMS   IconBms[6];

      SBBM    HighlightBm;
      SBBMS   IconsDefaultBms;
      SBBM    LockBm;

      SLONG   IconRot[6];
      SLONG   IconRotSpeed[6];

      //Bitmaps:
      SBBM    Window, BigWin;             //Das einfach und das doppelte Fenster
      SBBMS   Wallpapers;                 //Die Hintergr�nde
      SBBMS   Close;                      //Schlie�en des Fenster
      SBBMS   DownLeft;                   //bl�ttern
      SBBMS   DownRight;                  //bl�ttern
      SBBMS   UpLeft;                     //bl�ttern
      SBBMS   UpRight;                    //bl�ttern
      SBBMS   Inhalt;                     //Zum Inhalt
      SBBMS   Jump;                       //Springt ein Element vor oder zur�ck
      SBBMS   Switch;                     //Schaltet die Art des rechten Fenster
      SBBM    Karte;                      //Weltkarte
      SBBMS   EckBms;                     //Die vier Ecken zum aufblenden...
      SBBMS   PlaneRouteBms;              //Die Buttons um die Routen/Planes anzuzeigen;
      SBBMS   ScrollBms;

      //Sonstiges:
      GfxLib *pGLibGlobe;                 //Library f�r den Raum: Animationen der Objekte; wird immer geladen

      SBFX    StartupFX;

      SLONG   ScrollBlock;                //Id des Blocks wo man gerade am Scrollbar zerrt
      SLONG   ScrollSide;                 //Linke (0) oder rechte Seite (1) des Scrollbars
      XY      ScrollOffset;               //Offset beim Klick auf Scrollbar

      BOOL    Copyprotection;

      //Things for the three (blinking) Warning-Lights
      SBBMS   WarningLightBms;            //Warnings for order, freight orders and routes
      SLONG   WarningLightModes[3];       //0=Off, 1=On, 2=Blinking

   // Operations
   public:
   // Overrides
	   // ClassWizard generated virtual function overrides
	   //{{AFX_VIRTUAL(CLaptop)
	   //}}AFX_VIRTUAL

   // Implementation
   public:
	   ~CLaptop() override;

      void UpdateWarningLightModes (void);

	   // Generated message map functions
   protected:
	   //{{AFX_MSG(CLaptop)
	   void OnLButtonDown(UINT nFlags, CPoint point) override;
	   void OnLButtonUp(UINT nFlags, CPoint point) override;
	   void OnPaint() override;
	   void OnRButtonUp(UINT nFlags, CPoint point) override;
	   void OnRButtonDown(UINT nFlags, CPoint point) override;
	   void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) override;
	   void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) override;
      void OnLButtonDblClk(UINT nFlags, CPoint point) override;
	   //}}AFX_MSG
	   //DECLARE_MESSAGE_MAP()
};