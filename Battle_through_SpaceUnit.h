//---------------------------------------------------------------------------

#ifndef Battle_through_SpaceUnitH
#define Battle_through_SpaceUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ImgList.hpp>
#include <MPlayer.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TfrmLevel1 : public TForm
{
__published:	// IDE-managed Components
        TImage *bckSpace;
        TImage *craft1;
        TImage *craft2;
        TImage *craft3;
        TImage *craft4;
        TImage *craft6;
        TImage *craft5;
        TImage *craft7;
        TImage *craft8;
        TLabel *lblScore;
        TLabel *lblPlayer;
        TLabel *lblTotalScore;
        TImage *craft9;
        TImage *Alien1;
        TImage *Alien3;
        TImage *Alien2;
        TImage *Alien5;
        TImage *Alien4;
        TImage *Alien7;
        TImage *Alien16;
        TImage *Alien9;
        TImage *Alien10;
        TImage *Alien8;
        TImage *Alien11;
        TImage *Alien13;
        TImage *Alien12;
        TImage *Alien17;
        TImage *Alien18;
        TImage *Alien15;
        TImage *Alien14;
        TImage *Alien19;
        TImage *Alien20;
        TImage *Alien21;
        TImage *Alien22;
        TImage *Alien23;
        TImage *Alien24;
        TImage *Alien25;
        TMainMenu *MainMenu1;
        TMenuItem *Game1;
        TMenuItem *New1;
        TMenuItem *N1;
        TMenuItem *Close1;
        TMenuItem *Options1;
        TMenuItem *Help1;
        TMenuItem *About1;
        TMenuItem *Instructions1;
        TImage *bul1;
        TImage *bul3;
        TImage *bul4;
        TImage *bul5;
        TImage *bul6;
        TImage *bul7;
        TImage *bul8;
        TImage *bul9;
        TTimer *timerBullets;
        TTimer *timerAlliens;
        TImage *abul1;
        TImage *bul2;
        TImage *abul2;
        TImage *abul3;
        TImage *abul4;
        TImage *abul5;
        TImage *abul6;
        TTimer *timerAlienBulletsActivate;
        TImage *life1;
        TImage *life2;
        TImage *life3;
        TImage *life4;
        TImage *bonus5;
        TImage *bonus4;
        TImage *bonus3;
        TImage *bonus2;
        TImage *bonus1;
        TTimer *timerBonusActivate;
        TLabel *lblLevel;
        TMediaPlayer *mpMusic;
        TMenuItem *Music1;
        TMenuItem *Sound1;
        TMenuItem *On1;
        TMenuItem *Off1;
        TMenuItem *N2;
        TMenuItem *Off2;
        TMediaPlayer *mpExplode;
        TMenuItem *Track31;
        TMenuItem *Track41;
        TMenuItem *Track51;
        TMenuItem *N3;
        TMenuItem *MusicOff1;
        TLabel *lblGameStatus;
        TMenuItem *Pause1;
        TMenuItem *HighScores1;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Close1Click(TObject *Sender);
        void __fastcall New1Click(TObject *Sender);
        void __fastcall timerBulletsTimer(TObject *Sender);
        void __fastcall timerAlliensTimer(TObject *Sender);
        void __fastcall timerAlienBulletsActivateTimer(TObject *Sender);
        void __fastcall timerBonusActivateTimer(TObject *Sender);
        void __fastcall HighScore1Click(TObject *Sender);
        void __fastcall MusicOff1Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall Off2Click(TObject *Sender);
        void __fastcall Track31Click(TObject *Sender);
        void __fastcall Track41Click(TObject *Sender);
        void __fastcall Track51Click(TObject *Sender);
        void __fastcall Pause1Click(TObject *Sender);
        void __fastcall On1Click(TObject *Sender);
        void __fastcall Off1Click(TObject *Sender);
        void __fastcall HighScores1Click(TObject *Sender);
        void __fastcall Instructions1Click(TObject *Sender);
        void __fastcall About1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmLevel1(TComponent* Owner);
        bool Up_Down;
        int speed;
        int levelFin;
        int life;
        int KeyDisable;
        int frezeTime;
        int levelCount;
        int MusicOff;
        int SoundOff;
        int TotalScoreReset;

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmLevel1 *frmLevel1;
//---------------------------------------------------------------------------
#endif
