class CColorButton:public CButton
{
DECLARE_DYNAMIC(CColorButton)
public:
	CColorButton();
	virtual ~CColorButton();

	BOOL Attach(const UINT nID,CWnd* pParent,const COLORREF BGColor=RGB(192,192,192),
		const COLORREF FGColor=RGB(1,1,1),const COLORREF DisableedColor=RGB(128,128,128),
		const UINT nBevel=2);
protected:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);
	void DrawFrame(CDC*DC,CRect R,int Inset);
	void DrawFilledRect(CDC*DC,CRect R,COLORREF color);
	void DrawLine(CDC*DC,CRect EndPoints,COLORREF color);
	void DrawLine(CDC*DC,long left,long top,long right,long bottom,COLORREF color);
	void DrawButtonText(CDC*DC,CRect R,const char *Buf,COLORREF textcolor);
	COLORREF GetFGColor(){return m_fg;}
	COLORREF GetBGColor(){return m_bg;}
	COLORREF GetDisabledColor(){return m_disabled;}
	UINT GetBevel(){return m_bevel;}
private:
	COLORREF m_fg,m_bg,m_disabled;
	UINT m_bevel;
};



