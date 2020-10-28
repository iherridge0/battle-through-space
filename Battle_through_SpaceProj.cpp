//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Battle_through_SpaceUnit.cpp", frmLevel1);
USEFORM("WelcomeScreenUnit.cpp", frmWelcome);
USEFORM("HighScoresUnit.cpp", frmHighScores);
USEFORM("AboutUnit.cpp", frmAbout);
USEFORM("InstructionsUnit.cpp", frmInstructions);
USEFORM("NewNameUnit.cpp", frmEnterName);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TfrmWelcome), &frmWelcome);
                 Application->CreateForm(__classid(TfrmLevel1), &frmLevel1);
                 Application->CreateForm(__classid(TfrmHighScores), &frmHighScores);
                 Application->CreateForm(__classid(TfrmAbout), &frmAbout);
                 Application->CreateForm(__classid(TfrmInstructions), &frmInstructions);
                 Application->CreateForm(__classid(TfrmEnterName), &frmEnterName);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
