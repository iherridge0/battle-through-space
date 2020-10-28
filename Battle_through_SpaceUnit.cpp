//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Battle_through_SpaceUnit.h"
#include "WelcomeScreenUnit.h"
#include "HighScoresUnit.h"
#include "InstructionsUnit.h"
#include "AboutUnit.h"
#include "NewNameUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmLevel1 *frmLevel1;
//-----------------
void disableTimers();
void enableTimers();
void resetCraftBullets();
void resetAlienBullets();
void resetAliens();
void resetCrafts();
void resetLifes();
void resetBonus();
void newGame();
void aliensFreze();
void randomBonus();
void extraLife();
void resetLevel();
void bonusPoints();
void NextLevel();
void CheckLife();
void stageLife();
void Explode();
void ClearScreen();
void TrackSelect();
//-----------------
void disableTimers()
{
   frmLevel1->timerAlliens->Enabled = false;
   frmLevel1->timerAlienBulletsActivate->Enabled = false;
   frmLevel1->timerBullets->Enabled = false;
   frmLevel1->timerBonusActivate->Enabled = false;
   frmLevel1->timerBullets->Enabled = false;

}
//-----------------
void  enableTimers()
{
   frmLevel1->timerAlliens->Enabled = true;
   frmLevel1->timerAlienBulletsActivate->Enabled = true;
   frmLevel1->timerBullets->Enabled = true;
   frmLevel1->timerBonusActivate->Enabled = true;
   frmLevel1->timerBullets->Enabled = true;
}
//-----------------
void resetCraftBullets()
{
   for(int t = 0;t < frmLevel1->ComponentCount;t++)
   {
      if(frmLevel1->Components[t]->ClassNameIs("TImage") && frmLevel1->Components[t]->Tag == 2)
      {
         dynamic_cast <TImage*>(frmLevel1->Components[t])->Visible = false;
         dynamic_cast <TImage*>(frmLevel1->Components[t])->Left = 56;
      }
   }
}
//-----------------
void resetAlienBullets()
{
   for(int t = 0;t < frmLevel1->ComponentCount;t++)
   {
      if(frmLevel1->Components[t]->ClassNameIs("TImage") && frmLevel1->Components[t]->Tag == 3)
      {
         dynamic_cast <TImage*>(frmLevel1->Components[t])->Visible = false;
         dynamic_cast <TImage*>(frmLevel1->Components[t])->Left = 408;
      }
   }
}
//-----------------
void resetAliens()
{
   for(int t = 0;t < frmLevel1->ComponentCount;t++)
   {
      if(frmLevel1->Components[t]->ClassNameIs("TImage") && (frmLevel1->Components[t]->Tag == 5 || frmLevel1->Components[t]->Tag == 6 || frmLevel1->Components[t]->Tag == 7 || frmLevel1->Components[t]->Tag == 8))
      {
         dynamic_cast <TImage*>(frmLevel1->Components[t])->Visible = true;
      }
      if(frmLevel1->Components[t]->ClassNameIs("TImage") && frmLevel1->Components[t]->Tag == 5)
      {
         dynamic_cast <TImage*>(frmLevel1->Components[t])->Left = 592;

      }
      else
         if(frmLevel1->Components[t]->ClassNameIs("TImage") && frmLevel1->Components[t]->Tag == 6)
         {
            dynamic_cast <TImage*>(frmLevel1->Components[t])->Left = 536;
         }
         else
            if(frmLevel1->Components[t]->ClassNameIs("TImage") && frmLevel1->Components[t]->Tag == 7)
            {
               dynamic_cast <TImage*>(frmLevel1->Components[t])->Left = 480;
            }
            else
               if(frmLevel1->Components[t]->ClassNameIs("TImage") && frmLevel1->Components[t]->Tag == 8)
               {
                  dynamic_cast <TImage*>(frmLevel1->Components[t])->Left = 424;
               }
   }
   frmLevel1->timerAlliens->Interval = 900;
}
//-----------------
void resetCrafts()
{
   for(int t = 0;t < frmLevel1->ComponentCount;t++)
   {
      if(frmLevel1->Components[t]->ClassNameIs("TImage") && frmLevel1->Components[t]->Tag == 0)
      {
         dynamic_cast <TImage*>(frmLevel1->Components[t])->Visible = false;
      }
      else
         if(frmLevel1->Components[t]->ClassNameIs("TImage") && frmLevel1->Components[t]->Tag == 1)
         {
            dynamic_cast <TImage*>(frmLevel1->Components[t])->Visible = true;
         }
   }

}
//-----------------
void resetLifes()
{
   for(int t = 0;t < frmLevel1->ComponentCount;t++)
   {
      if(frmLevel1->Components[t]->ClassNameIs("TImage") && frmLevel1->Components[t]->Tag == 10)
      {
         dynamic_cast <TImage*>(frmLevel1->Components[t])->Visible = true;
      }
   }
}
//-----------------
void resetBonus()
{
   for(int t = 0;t < frmLevel1->ComponentCount;t++)
   {
      if(frmLevel1->Components[t]->ClassNameIs("TImage") && frmLevel1->Components[t]->Tag == 4)
      {
         dynamic_cast <TImage*>(frmLevel1->Components[t])->Visible = false;
      }
   }
}
//-----------------
void resetLevel()
{
   resetCraftBullets();
   resetAlienBullets();
}
//-----------------
void newGame()
{
   frmLevel1->lblGameStatus->Visible = false;
   resetCraftBullets();
   resetAlienBullets();
   resetAliens();
   enableTimers();
   resetCrafts();
   resetLifes();
   frmLevel1->KeyDisable = 0;
   resetBonus();
   if(frmLevel1->TotalScoreReset == 1)
   {
      frmLevel1->lblTotalScore->Caption = "0";
      frmLevel1->TotalScoreReset = 0;
   }
   if(frmLevel1->MusicOff == 0)
      TrackSelect();
   if(frmLevel1->life == 0)
   {   frmLevel1->life = 4;
       stageLife();
   }
}
//-----------------
void randomBonus()
{
   int number;
   number = random(3) + 1;
   switch (number)
   {
      case 1 : extraLife();
      break;
      case 2 : aliensFreze();
      break;
      case 3 : bonusPoints();
      break;
   }
}
//-----------------
void extraLife()
{
   int x = 0;
   if(frmLevel1->life2->Visible == false && x == 0)
   {
      frmLevel1->life2->Visible = true;
      x++;
   }
   if(frmLevel1->life3->Visible == false && x == 0)
   {
      frmLevel1->life3->Visible = true;
      x++;
   }
   if(frmLevel1->life4->Visible == false && x == 0)
   {
      frmLevel1->life4->Visible = true;
      x++;
   if(frmLevel1->life4->Visible == true && x == 0)
      bonusPoints();
   }
}
//-----------------
void aliensFreze()
{
   frmLevel1->timerAlliens->Enabled = false;
   frmLevel1->frezeTime = 2;
}
//-----------------

void bonusPoints()
{
   frmLevel1->lblTotalScore->Caption = frmLevel1->lblTotalScore->Caption.ToInt() + 100;
}
//-----------------
void NextLevel()
{
   int num = random(3);
   switch(num)
   {
      case 0 : for(int t = 0;t < frmLevel1->ComponentCount;t++)
               {
                  if(frmLevel1->Components[t]->ClassNameIs("TImage") && (frmLevel1->Components[t]->Tag == 5 || frmLevel1->Components[t]->Tag == 6 || frmLevel1->Components[t]->Tag == 7 || frmLevel1->Components[t]->Tag == 8))
                     dynamic_cast <TImage*>(frmLevel1->Components[t])->Picture->LoadFromFile("AllienCraft2.bmp");
               }
      break;
      case 1 : for(int t = 0;t < frmLevel1->ComponentCount;t++)
               {
                  if(frmLevel1->Components[t]->ClassNameIs("TImage") && (frmLevel1->Components[t]->Tag == 5 || frmLevel1->Components[t]->Tag == 6 || frmLevel1->Components[t]->Tag == 7 || frmLevel1->Components[t]->Tag == 8))
                     dynamic_cast <TImage*>(frmLevel1->Components[t])->Picture->LoadFromFile("AllienCraft1.bmp");
               }
      break;
      case 2 : for(int t = 0;t < frmLevel1->ComponentCount;t++)
               {
                  if(frmLevel1->Components[t]->ClassNameIs("TImage") && (frmLevel1->Components[t]->Tag == 5 || frmLevel1->Components[t]->Tag == 6 || frmLevel1->Components[t]->Tag == 7 || frmLevel1->Components[t]->Tag == 8))
                     dynamic_cast <TImage*>(frmLevel1->Components[t])->Picture->LoadFromFile("AllienCraft3.bmp");
               }
      break;
   }
   frmLevel1->MusicOff = 1;
   newGame();
   frmLevel1->MusicOff = 0;
   AnsiString level = "";
   AnsiString newLevel = "";
   frmLevel1->levelCount++;
   level = frmLevel1->lblLevel->Caption;
   level = level.Delete(7,7);
   level = level + frmLevel1->levelCount;
   frmLevel1->lblLevel->Caption = level;
   if(frmLevel1->timerAlienBulletsActivate->Interval > 100)
      frmLevel1->timerAlienBulletsActivate->Interval -= 100;
   frmLevel1->timerBonusActivate->Interval += 1000;
}

//-----------------
void CheckLife()
{
   if(frmLevel1->life4->Visible == true)
   {
      frmLevel1->life4->Visible = false;
      frmLevel1->life = 3;
   }
   else
      if(frmLevel1->life3->Visible == true)
      {
         frmLevel1->life3->Visible = false;
         frmLevel1->life = 2;
      }
      else
         if(frmLevel1->life2->Visible == true)
         {
            frmLevel1->life2->Visible = false;
            frmLevel1->life = 1;
         }
         else
            if(frmLevel1->life1->Visible == true)
            {
               frmLevel1->life1->Visible = false;
               frmLevel1->life = 0;
            }
}
//-----------------
void stageLife()
{
   if(frmLevel1->life == 4)
   {
      resetLifes();
      frmLevel1->life--;
   }
   else
      if(frmLevel1->life == 3)
      {
         resetLifes();
         frmLevel1->life4->Visible = false;
         frmLevel1->life--;
      }
      else
         if(frmLevel1->life == 2)
         {
            resetLifes();
            frmLevel1->life3->Visible = false;
            frmLevel1->life4->Visible = false;
            frmLevel1->life--;
         }
         else
            if(frmLevel1->life == 1)
            {
               resetLifes();
               frmLevel1->life2->Visible = false;
               frmLevel1->life3->Visible = false;
               frmLevel1->life4->Visible = false;
               frmLevel1->life--;
            }

}
//-----------------
void Explode()
{
   if(frmLevel1->SoundOff == 0)
   {
      frmLevel1->mpExplode->FileName = "\Sounds\\Crash.wav";
      frmLevel1->mpExplode->Open();
      frmLevel1->mpExplode->Play();
   }
}
//-----------------
void ClearScreen()
{
   for(int t = 0;t < frmLevel1->ComponentCount;t++)
   {
      if(frmLevel1->Components[t]->ClassNameIs("TImage") && frmLevel1->Components[t]->Tag != 9)
         dynamic_cast <TImage*>(frmLevel1->Components[t])->Visible = false;
   }
}
//-----------------
void TrackSelect()
{
   int num;
   AnsiString Ext = ".mp3";
   Randomize();
   num = random(5) + 1;
   switch(num)
   {
      case 1 : frmLevel1->mpMusic->FileName = "\Music\\Track 1.mp3";
      break;
      case 2 : frmLevel1->mpMusic->FileName = "\Music\\Track 2.mp3";
      break;
      case 3 : frmLevel1->mpMusic->FileName = "\Music\\Track 3.mp3";
      break;
      case 4 : frmLevel1->mpMusic->FileName = "\Music\\Track 4.mp3";
      break;
      case 5 : frmLevel1->mpMusic->FileName = "\Music\\Track 5.mp3";
      break;
   }
   frmLevel1->mpMusic->Open();
   frmLevel1->mpMusic->Play();
}
//-----------------
//-----------------
//---------------------------------------------------------------------------
__fastcall TfrmLevel1::TfrmLevel1(TComponent* Owner)
        : TForm(Owner)
{
   Up_Down = false;
   speed = 0;
   levelFin = 0;
   life = 4;
   KeyDisable = 0;
   frezeTime = 0;
   levelCount = 1;
   MusicOff = 0;
   SoundOff = 0;
   TotalScoreReset = 0;

}
//---------------------------------------------------------------------------

void __fastcall TfrmLevel1::FormShow(TObject *Sender)
{
   newGame();
   life = 1;
   lblTotalScore->Caption = "0";
   frmWelcome->Hide();
   for(int t = 0;t < ComponentCount;t++)
   {
      if(Components[t]->ClassNameIs("TImage") && (Components[t]->Tag == 5 || frmLevel1->Components[t]->Tag == 6 || frmLevel1->Components[t]->Tag == 7 || frmLevel1->Components[t]->Tag == 8))
      {
         dynamic_cast <TImage*>(Components[t])->Picture->LoadFromFile("AllienCraft2.bmp");
      }
   }
}
//---------------------------------------------------------------------------


void __fastcall TfrmLevel1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   int x = 0;
   int y = 0;
   if(Key == VK_DOWN && KeyDisable == 0)
   {
      if(craft1->Visible == true && x == 0)
      {
         craft1->Visible = false;
         craft2->Visible = true;
         x++;
      }
      if(craft2->Visible == true && x == 0)
      {
         craft2->Visible = false;
         craft3->Visible = true;
         x++;
      }
      if(craft3->Visible == true && x == 0)
      {
         craft3->Visible = false;
         craft4->Visible = true;
         x++;
      }
      if(craft4->Visible == true && x == 0)
      {
         craft4->Visible = false;
         craft5->Visible = true;
         x++;
      }
      if(craft5->Visible == true && x == 0)
      {
         craft5->Visible = false;
         craft6->Visible = true;
         x++;
      }
      if(craft6->Visible == true && x == 0)
      {
         craft6->Visible = false;
         craft7->Visible = true;
         x++;
      }
      if(craft7->Visible == true && x == 0)
      {
         craft7->Visible = false;
         craft8->Visible = true;
         x++;
      }
      if(craft8->Visible == true && x == 0)
      {
         craft8->Visible = false;
         craft9->Visible = true;
         x++;
      }
   }
   if(Key == VK_UP && KeyDisable == 0)
   {
      if(craft9->Visible == true && y == 0)
      {
         craft9->Visible = false;
         craft8->Visible = true;
         y++;
      }
      if(craft8->Visible == true && y == 0)
      {
         craft8->Visible = false;
         craft7->Visible = true;
         y++;
      }
      if(craft7->Visible == true && y == 0)
      {
         craft7->Visible = false;
         craft6->Visible = true;
         y++;
      }
      if(craft6->Visible == true && y == 0)
      {
         craft6->Visible = false;
         craft5->Visible = true;
         y++;
      }
      if(craft5->Visible == true && y == 0)
      {
         craft5->Visible = false;
         craft4->Visible = true;
         y++;
      }
      if(craft4->Visible == true && y == 0)
      {
         craft4->Visible = false;
         craft3->Visible = true;
         y++;
      }
      if(craft3->Visible == true && y == 0)
      {
         craft3->Visible = false;
         craft2->Visible = true;
         y++;
      }
      if(craft2->Visible == true && y == 0)
      {
         craft2->Visible = false;
         craft1->Visible = true;
         y++;
      }
   }
   if(Key == VK_SPACE && KeyDisable == 0)
   {
      if(craft1->Visible == true)
      {
         bul1->Visible = true;
      }
      if(craft2->Visible == true)
      {
         bul2->Visible = true;
      }
      if(craft3->Visible == true)
      {
         bul3->Visible = true;
      }
      if(craft4->Visible == true)
      {
         bul4->Visible = true;
      }
      if(craft5->Visible == true)
      {
         bul5->Visible = true;
      }
      if(craft6->Visible == true)
      {
         bul6->Visible = true;
      }
      if(craft7->Visible == true)
      {
         bul7->Visible = true;
      }
      if(craft8->Visible == true)
      {
         bul8->Visible = true;
      }
      if(craft9->Visible == true)
      {
         bul9->Visible = true;
      }
   }

}
//---------------------------------------------------------------------------
void __fastcall TfrmLevel1::Close1Click(TObject *Sender)
{
   frmLevel1->Close();
   frmWelcome->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmLevel1::New1Click(TObject *Sender)
{
   TotalScoreReset = 1;
   newGame();
}
//---------------------------------------------------------------------------
void __fastcall TfrmLevel1::timerBulletsTimer(TObject *Sender)
{
   if(bul1->Visible == true)
   {
      bul1->Left += 5;
      if((bul1->Left + bul1->Width) >= frmLevel1->Width - 30)
      {
         bul1->Visible = false;
         bul1->Left = 56;
      }
   }

   if(bul2->Visible == true)
   {
      bul2->Left += 5;
      if((bul2->Left + bul2->Width) >= frmLevel1->Width - 30)
      {
         bul2->Visible = false;
         bul2->Left = 56;
      }
   }

   if(bul3->Visible == true)
   {
      bul3->Left += 5;
      if((bul3->Left + bul3->Width) >= frmLevel1->Width - 30)
      {
         bul3->Visible = false;
         bul3->Left = 56;
      }
   }

   if(bul4->Visible == true)
   {
      bul4->Left += 5;
      if((bul4->Left + bul4->Width) >= frmLevel1->Width - 30)
      {
         bul4->Visible = false;
         bul4->Left = 56;
      }
   }

   if(bul5->Visible == true)
   {
      bul5->Left += 5;
      if((bul5->Left + bul5->Width) >= frmLevel1->Width - 30)
      {
         bul5->Visible = false;
         bul5->Left = 56;
      }
   }

   if(bul6->Visible == true)
   {
      bul6->Left += 5;
      if((bul6->Left + bul6->Width) >= frmLevel1->Width - 30)
      {
         bul6->Visible = false;
         bul6->Left = 56;
      }
   }

   if(bul7->Visible == true)
   {
      bul7->Left += 5;
      if((bul7->Left + bul7->Width) >= frmLevel1->Width - 30)
      {
         bul7->Visible = false;
         bul7->Left = 56;
      }
   }

   if(bul8->Visible == true)
   {
      bul8->Left += 5;
      if((bul8->Left + bul8->Width) >= frmLevel1->Width - 30)
      {
         bul8->Visible = false;
         bul8->Left = 56;
      }
   }

   if(bul9->Visible == true)
   {
      bul9->Left += 5;
      if((bul9->Left + bul9->Width) >= frmLevel1->Width - 30)
      {
         bul9->Visible = false;
         bul9->Left = 56;
      }
   }
//-----Allien-Bullet1------------------------
   if((bul1->Left + bul1->Width) >= Alien20->Left + 15 && bul1->Top  >= Alien20->Top && Alien20->Visible == true)
   {
      Alien20->Visible = false;
      bul1->Visible = false;
      bul1->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul1->Left + bul1->Width) >= Alien14->Left + 15 && bul1->Top  >= Alien14->Top && Alien14->Visible == true)
   {
      Alien14->Visible = false;
      bul1->Visible = false;
      bul1->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul1->Left + bul1->Width) >= Alien8->Left + 15 && bul1->Top  >= Alien8->Top && Alien8->Visible == true)
   {
      Alien8->Visible = false;
      bul1->Visible = false;
      bul1->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul1->Left + bul1->Width) >= Alien1->Left + 15 && bul1->Top  >= Alien1->Top && Alien1->Visible == true)
   {
      Alien1->Visible = false;
      bul1->Visible = false;
      bul1->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul2->Left + bul2->Width) >= Alien20->Left + 15 && bul2->Top  >= Alien20->Top && Alien20->Visible == true)
   {
      Alien20->Visible = false;
      bul2->Visible = false;
      bul2->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul2->Left + bul2->Width) >= Alien14->Left + 15 && bul2->Top  >= Alien14->Top && Alien14->Visible == true)
   {
      Alien14->Visible = false;
      bul2->Visible = false;
      bul2->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul2->Left + bul2->Width) >= Alien8->Left + 15 && bul2->Top  >= Alien8->Top && Alien8->Visible == true)
   {
      Alien8->Visible = false;
      bul2->Visible = false;
      bul2->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul2->Left + bul2->Width) >= Alien1->Left + 15 && bul2->Top  >= Alien1->Top && Alien1->Visible == true)
   {
      Alien1->Visible = false;
      bul2->Visible = false;
      bul2->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
//-----Allien-Bullet2------------------------
   if((bul2->Left + bul2->Width) >= Alien21->Left + 15 && bul2->Top  >= Alien21->Top && Alien21->Visible == true)
   {
      Alien21->Visible = false;
      bul2->Visible = false;
      bul2->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul2->Left + bul2->Width) >= Alien15->Left + 15 && bul2->Top  >= Alien15->Top && Alien15->Visible == true)
   {
      Alien15->Visible = false;
      bul2->Visible = false;
      bul2->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul2->Left + bul2->Width) >= Alien9->Left + 15 && bul2->Top  >= Alien9->Top && Alien9->Visible == true)
   {
      Alien9->Visible = false;
      bul2->Visible = false;
      bul2->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul2->Left + bul2->Width) >= Alien2->Left + 15 && bul2->Top  >= Alien2->Top && Alien2->Visible == true)
   {
      Alien2->Visible = false;
      bul2->Visible = false;
      bul2->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
//-----Allien-Bullet3------------------------
   if((bul3->Left + bul3->Width) >= Alien21->Left + 15 && bul3->Top  >= Alien21->Top && Alien21->Visible == true)
   {
      Alien21->Visible = false;
      bul3->Visible = false;
      bul3->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul3->Left + bul3->Width) >= Alien15->Left + 15 && bul3->Top  >= Alien15->Top && Alien15->Visible == true)
   {
      Alien15->Visible = false;
      bul3->Visible = false;
      bul3->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul3->Left + bul3->Width) >= Alien9->Left + 15 && bul3->Top  >= Alien9->Top && Alien9->Visible == true)
   {
      Alien9->Visible = false;
      bul3->Visible = false;
      bul3->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul3->Left + bul3->Width) >= Alien2->Left + 15 && bul3->Top  >= Alien2->Top && Alien2->Visible == true)
   {
      Alien2->Visible = false;
      bul3->Visible = false;
      bul3->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
//-----Allien-Bullet4------------------------
   if((bul4->Left + bul4->Width) >= Alien22->Left + 15 && bul4->Top  >= Alien22->Top && Alien22->Visible == true)
   {
      Alien22->Visible = false;
      bul4->Visible = false;
      bul4->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul4->Left + bul4->Width) >= Alien15->Left + 16 && bul4->Top  >= Alien16->Top && Alien16->Visible == true)
   {
      Alien16->Visible = false;
      bul4->Visible = false;
      bul4->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul4->Left + bul4->Width) >= Alien10->Left + 15 && bul4->Top  >= Alien10->Top && Alien10->Visible == true)
   {
      Alien10->Visible = false;
      bul4->Visible = false;
      bul4->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul4->Left + bul4->Width) >= Alien3->Left + 15 && bul4->Top  >= Alien3->Top && Alien3->Visible == true)
   {
      Alien3->Visible = false;
      bul4->Visible = false;
      bul4->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
//-----Allien-Bullet5------------------------
   if((bul5->Left + bul5->Width) >= Alien22->Left + 15 && bul5->Top  >= Alien22->Top && Alien22->Visible == true)
   {
      Alien22->Visible = false;
      bul5->Visible = false;
      bul5->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul5->Left + bul4->Width) >= Alien15->Left + 16 && bul5->Top  >= Alien16->Top && Alien16->Visible == true)
   {
      Alien16->Visible = false;
      bul5->Visible = false;
      bul5->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul5->Left + bul5->Width) >= Alien10->Left + 15 && bul5->Top  >= Alien10->Top && Alien10->Visible == true)
   {
      Alien10->Visible = false;
      bul5->Visible = false;
      bul5->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul5->Left + bul5->Width) >= Alien3->Left + 15 && bul5->Top  >= Alien3->Top && Alien3->Visible == true)
   {
      Alien3->Visible = false;
      bul5->Visible = false;
      bul5->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul5->Left + bul5->Width) >= Alien23->Left + 15 && bul5->Top  >= Alien23->Top && Alien23->Visible == true)
   {
      Alien23->Visible = false;
      bul5->Visible = false;
      bul5->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
    if((bul5->Left + bul5->Width) >= Alien17->Left + 15 && bul5->Top  >= Alien17->Top && Alien17->Visible == true)
   {
      Alien17->Visible = false;
      bul5->Visible = false;
      bul5->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
    if((bul5->Left + bul5->Width) >= Alien11->Left + 15 && bul5->Top  >= Alien11->Top && Alien11->Visible == true)
   {
      Alien11->Visible = false;
      bul5->Visible = false;
      bul5->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
    if((bul5->Left + bul5->Width) >= Alien4->Left + 15 && bul5->Top  >= Alien4->Top && Alien4->Visible == true)
   {
      Alien4->Visible = false;
      bul5->Visible = false;
      bul5->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
//-----Allien-Bullet6------------------------
   if((bul6->Left + bul6->Width) >= Alien23->Left + 15 && bul6->Top  >= Alien23->Top && Alien23->Visible == true)
   {
      Alien23->Visible = false;
      bul6->Visible = false;
      bul6->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul6->Left + bul6->Width) >= Alien17->Left + 15 && bul6->Top  >= Alien17->Top && Alien17->Visible == true)
   {
      Alien17->Visible = false;
      bul6->Visible = false;
      bul6->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul6->Left + bul6->Width) >= Alien11->Left + 15 && bul6->Top  >= Alien11->Top && Alien11->Visible == true)
   {
      Alien11->Visible = false;
      bul6->Visible = false;
      bul6->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul6->Left + bul6->Width) >= Alien4->Left + 15 && bul6->Top  >= Alien4->Top && Alien4->Visible == true)
   {
      Alien4->Visible = false;
      bul6->Visible = false;
      bul6->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
//-----Allien-Bullet7------------------------
   if((bul7->Left + bul7->Width) >= Alien24->Left + 15 && bul7->Top  >= Alien24->Top && Alien24->Visible == true)
   {
      Alien24->Visible = false;
      bul7->Visible = false;
      bul7->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul7->Left + bul7->Width) >= Alien18->Left + 15 && bul7->Top  >= Alien18->Top && Alien18->Visible == true)
   {
      Alien18->Visible = false;
      bul7->Visible = false;
      bul7->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
  if((bul7->Left + bul7->Width) >= Alien12->Left + 15 && bul7->Top  >= Alien12->Top && Alien12->Visible == true)
   {
      Alien12->Visible = false;
      bul7->Visible = false;
      bul7->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul7->Left + bul7->Width) >= Alien5->Left + 15 && bul7->Top  >= Alien5->Top && Alien5->Visible == true)
   {
      Alien5->Visible = false;
      bul7->Visible = false;
      bul7->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
//-----Allien-Bullet8------------------------
   if((bul8->Left + bul8->Width) >= Alien24->Left + 15 && bul8->Top  >= Alien24->Top && Alien24->Visible == true)
   {
      Alien24->Visible = false;
      bul8->Visible = false;
      bul8->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul8->Left + bul8->Width) >= Alien18->Left + 15 && bul8->Top  >= Alien18->Top && Alien18->Visible == true)
   {
      Alien18->Visible = false;
      bul8->Visible = false;
      bul8->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
  if((bul8->Left + bul8->Width) >= Alien12->Left + 15 && bul8->Top  >= Alien12->Top && Alien12->Visible == true)
   {
      Alien12->Visible = false;
      bul8->Visible = false;
      bul8->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul8->Left + bul8->Width) >= Alien5->Left + 15 && bul8->Top  >= Alien5->Top && Alien5->Visible == true)
   {
      Alien5->Visible = false;
      bul8->Visible = false;
      bul8->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul8->Left + bul8->Width) >= Alien25->Left + 15 && bul8->Top  >= Alien25->Top && Alien25->Visible == true)
   {
      Alien25->Visible = false;
      bul8->Visible = false;
      bul8->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul8->Left + bul8->Width) >= Alien19->Left + 15 && bul8->Top  >= Alien19->Top && Alien19->Visible == true)
   {
      Alien19->Visible = false;
      bul8->Visible = false;
      bul8->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul8->Left + bul8->Width) >= Alien13->Left + 15 && bul8->Top  >= Alien13->Top && Alien13->Visible == true)
   {
      Alien13->Visible = false;
      bul8->Visible = false;
      bul8->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul8->Left + bul8->Width) >= Alien7->Left + 15 && bul8->Top  >= Alien7->Top && Alien7->Visible == true)
   {
      Alien7->Visible = false;
      bul8->Visible = false;
      bul8->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
//-----Allien-Bullet9------------------------
   if((bul9->Left + bul9->Width) >= Alien25->Left + 15 && bul9->Top  >= Alien25->Top && Alien25->Visible == true)
   {
      Alien25->Visible = false;
      bul9->Visible = false;
      bul9->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul9->Left + bul9->Width) >= Alien19->Left + 15 && bul9->Top  >= Alien19->Top && Alien19->Visible == true)
   {
      Alien19->Visible = false;
      bul9->Visible = false;
      bul9->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul9->Left + bul9->Width) >= Alien13->Left + 15 && bul9->Top  >= Alien13->Top && Alien13->Visible == true)
   {
      Alien13->Visible = false;
      bul9->Visible = false;
      bul9->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
   if((bul9->Left + bul9->Width) >= Alien7->Left + 15 && bul9->Top  >= Alien7->Top && Alien7->Visible == true)
   {
      Alien7->Visible = false;
      bul9->Visible = false;
      bul9->Left = 56;
      lblTotalScore->Caption = lblTotalScore->Caption.ToInt() + 10;
      Explode();
   }
//----------AlienBullets--------------
   if(abul1->Visible == true)
   {
    abul1->Left -= 5;
    if(abul1->Left < (craft1->Left + craft1->Width))
    {
      if(craft1->Visible == true)
      {
         Explode();
         resetCrafts();
         abul2->Left = 408;
         abul1->Visible = false;
         CheckLife();
      }
      if(abul1->Left < 5)
      {
         abul1->Left = 408;
         abul1->Visible = false;
      }
    }
   }

   if(abul2->Visible == true)
   {
    abul2->Left -= 5;
    if(abul2->Left < (craft3->Left + craft3->Width))
    {
       if(craft3->Visible == true)
       {
          Explode();
          resetCrafts();
          abul2->Left = 408;
          abul2->Visible = false;
          CheckLife();
       }
       if(abul2->Left < 5)
       {
          abul2->Left = 408;
          abul2->Visible = false;
       }
    }
   }

   if(abul3->Visible == true)
   {
    abul3->Left -= 5;
    if(abul3->Left < (craft4->Left + craft4->Width))
    {
       if(craft4->Visible == true)
       {
          Explode();
          resetCrafts();
          abul3->Left = 408;
          abul3->Visible = false;
          CheckLife();
       }
       if(abul3->Left < 5)
       {
          abul3->Left = 408;
          abul3->Visible = false;
       }
    }
   }

   if(abul4->Visible == true)
   {
    abul4->Left -= 5;
    if(abul4->Left < (craft6->Left + craft6->Width))
    {
       if(craft6->Visible == true)
       {
          Explode();
          resetCrafts();
          abul4->Left = 408;
          abul4->Visible = false;
          CheckLife();
       }
       if(abul4->Left < 5)
       {
          abul4->Left = 408;
          abul4->Visible = false;
       }
    }
   }

   if(abul5->Visible == true)
   {
    abul5->Left -= 5;
    if(abul5->Left < (craft7->Left + craft7->Width))
    {
       if(craft7->Visible == true)
       {
          Explode();
          resetCrafts();
          abul5->Left = 408;
          abul5->Visible = false;
          CheckLife();
       }
       if(abul5->Left < 5)
       {
          abul5->Left = 408;
          abul5->Visible = false;
       }
    }
   }
   if(abul6->Visible == true)
   {
    abul6->Left -= 5;
    if(abul6->Left < (craft9->Left + craft9->Width))
    {
       if(craft9->Visible == true)
       {
          Explode();
          resetCrafts();
          abul6->Left = 408;
          abul6->Visible = false;
          CheckLife();
       }
       if(abul6->Left < 5)
       {
          abul6->Left = 408;
          abul6->Visible = false;
       }
    }
   }
//-------Bonus-Stuff------------
   if(bonus1->Visible == true)
   {
      bonus1->Left -= 5;
      if(bonus1->Left < (craft2->Left + craft2->Width) && craft2->Visible == true)
      {
         Explode();
         bonus1->Visible = false;
         bonus1->Left = 624;
         randomBonus();
      }
      else
      if(bonus1->Left < 5)
      {
         bonus1->Visible = false;
         bonus1->Left = 624;
      }
   }

   if(bonus2->Visible == true)
   {
      bonus2->Left -= 5;
      if(bonus2->Left < (craft3->Left + craft3->Width) && craft3->Visible == true)
      {
         Explode();
         bonus2->Visible = false;
         bonus2->Left = 624;
         randomBonus();
      }
      else
         if(bonus2->Left < 5)
         {
            bonus2->Visible = false;
            bonus2->Left = 624;
         }
   }

   if(bonus3->Visible == true)
   {
      bonus3->Left -= 5;
      if(bonus3->Left < (craft5->Left + craft5->Width) && craft5->Visible == true)
      {
         Explode();
         bonus3->Visible = false;
         bonus3->Left = 624;
         randomBonus();
      }
      else
         if(bonus3->Left < 5)
         {
            bonus3->Visible = false;
            bonus3->Left = 624;
         }
   }

   if(bonus4->Visible == true)
   {
      bonus4->Left -= 5;
      if(bonus4->Left < (craft6->Left + craft6->Width) && craft6->Visible == true)
      {
         Explode();
         bonus4->Visible = false;
         bonus4->Left = 624;
         randomBonus();
      }
      else
        if(bonus4->Left < 5)
        {
            bonus4->Visible = false;
            bonus4->Left = 624;
         }
   }

   if(bonus5->Visible == true)
   {
      bonus5->Left -= 5;
      if(bonus5->Left < (craft8->Left + craft8->Width) && craft8->Visible == true)
      {
         Explode();
         bonus5->Visible = false;
         bonus5->Left = 624;
         randomBonus();
      }
      else
         if(bonus5->Left < 5)
         {
            bonus5->Visible = false;
            bonus5->Left = 624;
         }
   }
}
//---------------------------------------------------------------------------


void __fastcall TfrmLevel1::timerAlliensTimer(TObject *Sender)
{
   if(Alien1->Visible == false && Alien2->Visible == false && Alien3->Visible == false && Alien4->Visible == false && Alien5->Visible == false && Alien7->Visible == false && Alien8->Visible == false && Alien9->Visible == false && Alien10->Visible == false && Alien11->Visible == false && Alien12->Visible == false && Alien13->Visible == false && Alien14->Visible == false && Alien15->Visible == false && Alien16->Visible == false &&  Alien17->Visible == false &&  Alien18->Visible == false && Alien19->Visible == false && Alien20->Visible == false && Alien21->Visible == false && Alien22->Visible == false && Alien23->Visible == false && Alien24->Visible == false && Alien25->Visible == false)
   {
       NextLevel();
   }
   if(life == 0)
   {
      TotalScoreReset = 1;


      mpMusic->Stop();
      KeyDisable = 1;
      disableTimers();
      resetLevel();
      life = 1;
      KeyDisable = 1;
      ClearScreen();
      lblGameStatus->Visible = true;

      AnsiString Name = "";
      AnsiString Temp = "";
      TStringList *list;
      list = new TStringList;
      list->Clear();
      list->LoadFromFile("\Data\\High_Scores.sif");

      frmEnterName->ShowModal();
      Name = frmEnterName->edtName->Text;
      list->Add(lblTotalScore->Caption + " " + Name);
      list->SaveToFile("\Data\\High_Scores.sif");

   }

   if(Up_Down == true)
   {
      for(int t = 0;t < frmLevel1->ComponentCount;t++)
      {
         if(frmLevel1->Components[t]->ClassNameIs("TImage") && (frmLevel1->Components[t]->Tag == 5 || frmLevel1->Components[t]->Tag == 6 || frmLevel1->Components[t]->Tag == 7 || frmLevel1->Components[t]->Tag == 8))
         {
            dynamic_cast <TImage*>(frmLevel1->Components[t])->Top -= 5;
         }
      }
   }
   if(Up_Down == false)
   {
      for(int t = 0;t < frmLevel1->ComponentCount;t++)
      {
         if(frmLevel1->Components[t]->ClassNameIs("TImage") && (frmLevel1->Components[t]->Tag == 5 || frmLevel1->Components[t]->Tag == 6 || frmLevel1->Components[t]->Tag == 7 || frmLevel1->Components[t]->Tag == 8))
         {
            dynamic_cast <TImage*>(frmLevel1->Components[t])->Top += 5;
         }
      }
   }
   if(Alien1->Top < 30)
   {
       Up_Down = false;
       for(int t = 0;t < frmLevel1->ComponentCount;t++)
      {
         if(frmLevel1->Components[t]->ClassNameIs("TImage") && (frmLevel1->Components[t]->Tag == 5 || frmLevel1->Components[t]->Tag == 6 || frmLevel1->Components[t]->Tag == 7 || frmLevel1->Components[t]->Tag == 8))
         {
            dynamic_cast <TImage*>(frmLevel1->Components[t])->Left -= 5;
         }
      }
   }
   if((Alien7->Top + Alien7->Height) > frmLevel1->ClientHeight - 10)
   {
      Up_Down = true;
      for(int t = 0;t < frmLevel1->ComponentCount;t++)
      {
         if(frmLevel1->Components[t]->ClassNameIs("TImage") && (frmLevel1->Components[t]->Tag == 5 || frmLevel1->Components[t]->Tag == 6 || frmLevel1->Components[t]->Tag == 7 || frmLevel1->Components[t]->Tag == 8))
         {
            dynamic_cast <TImage*>(frmLevel1->Components[t])->Left -= 5;
         }
      }
   }
   speed++;
   if(speed == 10)
   {
      if(timerAlliens->Interval == 100)
         timerAlliens->Interval;
      else
      {
         timerAlliens->Interval -= 100;
         speed = 0;
      }

   }
}
//---------------------------------------------------------------------------



void __fastcall TfrmLevel1::timerAlienBulletsActivateTimer(TObject *Sender)
{
  int number;
  number = random(6) + 1;
  switch (number)
  {
     case 1 : abul1->Visible = true;
     break;
     case 2 : abul2->Visible = true;
     break;
     case 3 : abul3->Visible = true;
     break;
     case 4 : abul4->Visible = true;
     break;
     case 5 : abul5->Visible = true;
     break;
     case 6 : abul6->Visible = true;
     break;
  }

}
//---------------------------------------------------------------------------
void __fastcall TfrmLevel1::timerBonusActivateTimer(TObject *Sender)
{
  int number;
  number = random(5) + 1;
  switch (number)
  {
     case 1 : bonus1->Visible = true;
     break;
     case 2 : bonus2->Visible = true;
     break;
     case 3 : bonus3->Visible = true;
     break;
     case 4 : bonus4->Visible = true;
     break;
     case 5 : bonus5->Visible = true;
     break;
  }
  timerAlliens->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmLevel1::HighScore1Click(TObject *Sender)
{
   frmHighScores->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmLevel1::MusicOff1Click(TObject *Sender)
{
   MusicOff = 1;
   mpMusic->Stop();
}
//---------------------------------------------------------------------------

void __fastcall TfrmLevel1::N2Click(TObject *Sender)
{
   MusicOff = 0;
   mpMusic->FileName = "\Music\\Track 1.mp3";
   mpMusic->Open();
   mpMusic->Play();
}
//---------------------------------------------------------------------------

void __fastcall TfrmLevel1::Off2Click(TObject *Sender)
{
   MusicOff = 0;
   mpMusic->FileName = "\Music\\Track 2.mp3";
   mpMusic->Open();
   mpMusic->Play();
}
//---------------------------------------------------------------------------

void __fastcall TfrmLevel1::Track31Click(TObject *Sender)
{
   MusicOff = 0;
   mpMusic->FileName = "\Music\\Track 3.mp3";
   mpMusic->Open();
   mpMusic->Play();
}
//---------------------------------------------------------------------------

void __fastcall TfrmLevel1::Track41Click(TObject *Sender)
{
   MusicOff = 0;
   mpMusic->FileName = "\Music\\Track 4.mp3";
   mpMusic->Open();
   mpMusic->Play();
}
//---------------------------------------------------------------------------

void __fastcall TfrmLevel1::Track51Click(TObject *Sender)
{
   MusicOff = 0;
   mpMusic->FileName = "\Music\\Track 5.mp3";
   mpMusic->Open();
   mpMusic->Play();
}
//---------------------------------------------------------------------------

void __fastcall TfrmLevel1::Pause1Click(TObject *Sender)
{
   if(Pause1->Checked == true)
   {
      enableTimers();
      Pause1->Checked = false;
      mpMusic->Play();
   }
   else
      if(Pause1->Checked == false)
      {
         disableTimers();
         Pause1->Checked = true;
         mpMusic->Pause();
      }
}
//---------------------------------------------------------------------------

void __fastcall TfrmLevel1::On1Click(TObject *Sender)
{
    SoundOff = 0;        
}
//---------------------------------------------------------------------------

void __fastcall TfrmLevel1::Off1Click(TObject *Sender)
{
   SoundOff = 1;        
}
//---------------------------------------------------------------------------

void __fastcall TfrmLevel1::HighScores1Click(TObject *Sender)
{
  frmHighScores->ShowModal();        
}
//---------------------------------------------------------------------------


void __fastcall TfrmLevel1::Instructions1Click(TObject *Sender)
{
   Pause1Click(this);
   frmInstructions->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmLevel1::About1Click(TObject *Sender)
{

   Pause1Click(this);
   frmAbout->ShowModal();
}
//---------------------------------------------------------------------------

