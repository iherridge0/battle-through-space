//---------------------------------------------------------------------------

#ifndef NewNameUnitH
#define NewNameUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmEnterName : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *edtName;
        TBitBtn *BitBtn1;
private:	// User declarations
public:		// User declarations
        __fastcall TfrmEnterName(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmEnterName *frmEnterName;
//---------------------------------------------------------------------------
#endif
