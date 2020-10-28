//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AboutUnit.h"
#include "Battle_through_SpaceUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAbout *frmAbout;
//---------------------------------------------------------------------------
__fastcall TfrmAbout::TfrmAbout(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmAbout::FormClose(TObject *Sender, TCloseAction &Action)
{
    frmLevel1->Pause1Click(this);
}
//---------------------------------------------------------------------------


