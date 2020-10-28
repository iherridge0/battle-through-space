//---------------------------------------------------------------------------

#ifndef WelcomeScreenUnitH
#define WelcomeScreenUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TfrmWelcome : public TForm
{
__published:	// IDE-managed Components
        TTimer *timerFrmClose;
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        void __fastcall timerFrmCloseTimer(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormHide(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmWelcome(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmWelcome *frmWelcome;
//---------------------------------------------------------------------------
#endif
