//---------------------------------------------------------------------------

#ifndef InstructionsUnitH
#define InstructionsUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfrmInstructions : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TMemo *Memo1;
        TImage *Image1;
        TImage *Image3;
        TImage *Image4;
        TImage *Image5;
        TImage *Image2;
        TImage *Image6;
        TImage *Image7;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TPanel *Panel1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmInstructions(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmInstructions *frmInstructions;
//---------------------------------------------------------------------------
#endif
