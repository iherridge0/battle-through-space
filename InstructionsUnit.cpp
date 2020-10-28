//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "InstructionsUnit.h"
#include "Battle_through_SpaceUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmInstructions *frmInstructions;
//---------------------------------------------------------------------------
__fastcall TfrmInstructions::TfrmInstructions(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmInstructions::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   frmLevel1->Pause1Click(this);
}
//---------------------------------------------------------------------------
