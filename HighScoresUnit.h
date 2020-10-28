//---------------------------------------------------------------------------

#ifndef HighScoresUnitH
#define HighScoresUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
//---------------------------------------------------------------------------
class TfrmHighScores : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TBitBtn *BitBtn1;
        TStringGrid *strgrHighScores;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmHighScores(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmHighScores *frmHighScores;
//---------------------------------------------------------------------------
#endif
