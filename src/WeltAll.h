//============================================================================================
// WeltAll.h : Das Fernglass ins WeltAll
//============================================================================================

class CSternschnuppe
{
   private:
      SLONG StartIndex;                          //0-2 oder -1= Empty

      XY    Position;                            //Festkommaarythmetik: Durch 256 Teilen
      XY    Velocity;                            //Festkommaarythmetik: Durch 256 Teilen

   private:
      CSternschnuppe () { StartIndex=-1; }

   friend class CWeltAll;
};

class CWeltAll : public CStdRaum
{
// Construction
public:
	CWeltAll(BOOL bHandy, ULONG PlayerNum);

// Data
public:
   SBBMS         FernglasBms;                    //Der Rand vom Fernglas
   SBBM          SpaceBm;                        //Das Hintergrundbild

   SBBMS         StationBms;                     //Die 10 (farblich neutralen) Bilder der Station
   SBBMS         Ring1ColorBms;                  //Die vier Farblichen Bilder f�r Ring 1
   SBBMS         Ring2ColorBms;                  //Die vier Farblichen Bilder f�r Ring 2
   SBBMS         Ring3ColorBms;                  //Die vier Farblichen Bilder f�r Ring 3
   SBBMS         O2ColorBms;                     //Die vier Farblichen Bilder f�r die Sauerstofftanks
   SBBM          CentralL;                       //Die Zentrale mit Licht
   SBBM          BusinessL;                      //Der Gesch�ftsbereich mit Licht
   SBBM          CommL;                          //Die Antenne mit Licht
   SBBM          LivingL;                        //Der Gesch�ftsbereich mit Licht

   SBBMS         StarBms;                        //Die Sternschnuppen

   SLONG         BlinkArrowsTimer;               //Die blinkenden Pfeile
   SLONG         LastTime;                       //F�r Animationen

   CSternschnuppe Sternschnuppen[20];
   CSmackerPerson SP_Flags[4];
   CSmackerPerson SP_Ufo;

   XY             UfoPosition;
   XY             UfoVelocity;
   SLONG          UfoNumSteps;
   SLONG          UfoWaitTill;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeltAll)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CWeltAll() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(CWeltAll)
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
