//============================================================================================
// Designer.h : Der Designer-Raum!
//============================================================================================

class CDesigner : public CStdRaum
{
// Construction
public:
	CDesigner(BOOL bHandy, ULONG PlayerNum);

// Data
public:
   CSmackerPerson SP_Stan;
   CSmackerPerson SP_Bein;
   CSmackerPerson SP_Bat;
   CSmackerPerson SP_Blender;
   CSmackerPerson SP_Schwalbe;

   SBFX           BackFx;

   SLONG          CurrentTip;          //Dieser Tip wird gerade angezeigt

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesigner)
	//}}AFX_VIRTUAL

// Implementation
public:
	~CDesigner() override;

	// Generated message map functions
protected:
	//{{AFX_MSG(CDesigner)
	void OnLButtonDown(UINT nFlags, CPoint point) override;
	void OnPaint() override;
	void OnRButtonDown(UINT nFlags, CPoint point) override;
	//}}AFX_MSG
	//DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
