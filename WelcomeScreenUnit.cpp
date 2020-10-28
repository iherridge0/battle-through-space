//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "WelcomeScreenUnit.h"
#include "Battle_through_SpaceUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmWelcome *frmWelcome;
//---------------------------------------------------------------------------
__fastcall TfrmWelcome::TfrmWelcome(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmWelcome::timerFrmCloseTimer(TObject *Sender)
{
   frmWelcome->Hide();        
}
//---------------------------------------------------------------------------

void __fastcall TfrmWelcome::FormShow(TObject *Sender)
{
   frmLevel1->Pause1Click(this);
   frmLevel1->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TfrmWelcome::FormHide(TObject *Sender)
{
   frmLevel1->Pause1Click(this);
   frmLevel1->Visible = true;
}
//---------------------------------------------------------------------------

