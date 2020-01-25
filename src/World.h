//============================================================================================
// World.h : Das weltweite Telefonat
//============================================================================================

class CWorld : public CStdRaum
{
// Construction
public:
	CWorld(BOOL bHandy, ULONG PlayerNum, SLONG CityId);

   SLONG          CityId;
   XY             SpeakCenter;
   CSmackerPerson SP_Ping;

   TECBM          EarthBm;

   SBBM           Satellite;
   CAnimation     LightAnim;
   CAnimation     SendingAnim;

   SBBM           WhiteBm;
   SLONG          TimeStart;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorld)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CWorld() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(CWorld)
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
