//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HighScoresUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmHighScores *frmHighScores;
//---------------------------------------------------------------------------
__fastcall TfrmHighScores::TfrmHighScores(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmHighScores::FormShow(TObject *Sender)
{
   strgrHighScores->Cells[0][0] = "Name";
   strgrHighScores->Cells[1][0] = "Score";
   AnsiString Temp = "",v1,v2;

      TStringList *list;
      list = new TStringList;
      list->Clear();
      list->LoadFromFile("\Data\\High_Scores.sif");
      for(int x = 0;x < list->Count-1;x++)
      {
         for(int y = 0; y < list->Count-1;y++)
         {
            v1 = list->Strings[y+1].SubString(1,list->Strings[y+1].Pos(" ")-1);
            v2 = list->Strings[y].SubString(1,list->Strings[y].Pos(" ")-1);
            if(v1.ToInt() > v2.ToInt())
            {
               Temp = list->Strings[y];
               list->Strings[y] = list->Strings[y+1];
               list->Strings[y+1] = Temp;
            }
         }
      }
      for(int q = 0;q < list->Count;q++)
      {
         Temp = list->Strings[q];
         frmHighScores->strgrHighScores->Cells[1][q+1] = Temp.SubString(1,Temp.Pos(" ")-1);
         Temp = Temp.Delete(1,Temp.Pos(" "));
         frmHighScores->strgrHighScores->Cells[0][q+1] = Temp;
      }
      list->SaveToFile("\Data\\High_Scores.sif");

}
//---------------------------------------------------------------------------

