//---------------------------------------------------------------------------

#include <vcl.h>
#include<cstdlib>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int xBall=8, yBall=8;

int numberOfBounces=0, playerPoints1=0, playerPoints2=0;

bool isBallInMiddle(TImage * ball, TImage * paddle)
{
    if((ball->Top+ball->Height/2 > (paddle->Top+paddle->Height*0.4)) &&
        (ball->Top+ball->Height/2 < paddle->Top+paddle->Height*0.6))
    {
        return true;
    }
    else
        return false;
}
void speedUpBall(TImage * ball, TImage * paddle)
{
    if(isBallInMiddle(ball, paddle))
    {
        if(abs(xBall)<20)
        {
            xBall *= 1.25;
            yBall *= 1.2;
        }
        else
        {
            xBall=xBall/abs(xBall)*(abs(xBall)+1);
        }
    }
}

void startGame(TImage * Ball, TTimer * BallTimer, TTimer * Paddle1_Up,
TTimer * Paddle1_Down, TTimer * Paddle2_Up, TTimer * Paddle2_Down,
TButton * Button1, TButton * Button2, TLabel * Label1, TLabel * Label2,
TLabel * Label3)
{    /*
    B->Left = 500;
    B->Top = 200;
    xBall=8; yBall=8;
    B->Visible = true;
    BallTimer->Enabled = true;
    Paddle1_Up->Enabled = true;
    Paddle1_Down->Enabled = true;
    Paddle2_Up->Enabled = true;
    Paddle2_Down->Enabled = true;
    numberOfBounces = 0;
    Button1->Visible = false;
    Button2->Visible = false;
    Label1->Visible = false;
    Label2->Visible = false;
    Label3->Visible = false;    */
}

void stopGame(TImage * Ball, TTimer * BallTimer, TButton * Button1,
TButton * Button2, TLabel * Label1, TLabel * Label2, TLabel * Label3)
{   /*
    Ball->Visible = false;
    BallTimer->Enabled = false;
    Label1->Visible = true;
    Label2->Visible = true;
    Label3->Visible = true;
    Button2->Visible = true;
    Button1->Visible = true;  */
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle1_UpTimer(TObject *Sender)
{
    if(P1->Top > 10) P1->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle1_DownTimer(TObject *Sender)
{
    if(P1->Top+P1->Height < Background->Height-10) P1->Top +=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle2_UpTimer(TObject *Sender)
{
    if(P2->Top > 10) P2->Top -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Paddle2_DownTimer(TObject *Sender)
{
    if(P2->Top+P2->Height < Background->Height-10) P2->Top +=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_UP) Paddle1_Up->Enabled = true;
    if(Key == VK_DOWN) Paddle1_Down->Enabled = true;
    if(Key == 'A') Paddle2_Up->Enabled = true;
    if(Key == 'Z') Paddle2_Down->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_UP) Paddle1_Up->Enabled = false;
    if(Key == VK_DOWN) Paddle1_Down->Enabled = false;
    if(Key == 'A') Paddle2_Up->Enabled = false;
    if(Key == 'Z') Paddle2_Down->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BallTimerTimer(TObject *Sender)
{
    B->Left += xBall;
    B->Top += yBall;

    if(B->Top-10 <= Background->Top) //upper limit
    {
        yBall=-yBall;
        sndPlaySound("snd/pilka.wav", SND_ASYNC);
    }

    if(B->Top+B->Height+10 >= Background->Height)    //lower limit
    {
        yBall=-yBall;
        sndPlaySound("snd/pilka.wav", SND_ASYNC);
    }

    if (B->Left+B->Width >= P1->Left+P1->Width+20) //loss P1
    {
        playerPoints2++;
        Label1->Caption = "< Punkt dla gracza lewego";
        //stopGame(B, BallTimer, Button1, Button2, Label1, Label2, Label3);
        B->Visible = false;
        BallTimer->Enabled = false;
        Label1->Visible = true;
        Label2->Visible = true;
        Label3->Visible = true;
        Button2->Visible = true;
        Button1->Visible = true;
        xBall=8; yBall=8;

        sndPlaySound("snd/koniec.wav", SND_ASYNC);
    }
    else if (B->Left <= P2->Left-20) //loss P2
    {
        playerPoints1++;
        Label1->Caption = "Punkt dla gracza prawego >";
        //stopGame(B, BallTimer, Button1, Button2, Label1, Label2, Label3);
        B->Visible = false;
        BallTimer->Enabled = false;
        Label1->Visible = true;
        Label2->Visible = true;
        Label3->Visible = true;
        Button2->Visible = true;
        Button1->Visible = true;
        xBall=-8; yBall=-8;

        sndPlaySound("snd/koniec.wav", SND_ASYNC);
    }
    else if ((B->Top > (P1->Top-B->Height/2)) && (B->Top < P1->Top+P1->Height) &&  //bounce P1
    (B->Left+B->Width > P1->Left))
    {
        if(xBall>0)
        {
            xBall=-xBall;
            speedUpBall(B, P1);
            numberOfBounces++;
            sndPlaySound("snd/pilka.wav", SND_ASYNC);
        }
    }
    else if ((B->Top > (P2->Top-B->Height/2)) && (B->Top < P2->Top+P2->Height) &&  //bounce P2
    (B->Left < P2->Left+P2->Width))
    {
        if(xBall<0)
        {
            xBall=-xBall;
            speedUpBall(B, P2);
            numberOfBounces++;
            sndPlaySound("snd/pilka.wav", SND_ASYNC);
        }
    }

    Label2->Caption = IntToStr(playerPoints2) + " : " + IntToStr(playerPoints1);
    Label3->Caption = "Ilo\211\255\199\213 odbi\143: " + IntToStr(numberOfBounces);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if(playerPoints1 || playerPoints2)
    {
        if(Application->MessageBox("Czy na pewno chcesz zacz¹æ grê od nowa?", "PotwierdŸ",
        MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
            Form1->Label1->Caption = "Runda za: 2";
            Application->ProcessMessages(); Sleep(1000);
            Form1->Label1->Caption = "Runda za: 1";
            Application->ProcessMessages(); Sleep(1000);

            playerPoints1 = 0;
            playerPoints2 = 0;

            B->Left = 500;
            B->Top = 200;
            B->Visible = true;
            BallTimer->Enabled = true;

            numberOfBounces = 0;

            Button1->Visible = false;
            Button2->Visible = false;
            Label1->Visible = false;
            Label2->Visible = false;
            Label3->Visible = false;

            sndPlaySound("snd/start.wav", SND_ASYNC);
        }
    }
    else
    {
        Form1->Label1->Caption = "Runda za: 2";
        Application->ProcessMessages(); Sleep(1000);
        Form1->Label1->Caption = "Runda za: 1";
        Application->ProcessMessages(); Sleep(1000);

        BallTimer->Enabled = true;

        Button1->Visible = false;
        Label1->Visible = false;

        sndPlaySound("snd/start.wav", SND_ASYNC);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    //startGame(B, BallTimer, Paddle1_Up, Paddle1_Down, Paddle2_Up, Paddle2_Down, Button1, Button2, Label1, Label2, Label3);

    Form1->Label1->Caption = "Runda za: 2";
    Application->ProcessMessages(); Sleep(1000);
    Form1->Label1->Caption = "Runda za: 1";
    Application->ProcessMessages(); Sleep(1000);

    B->Left = 500;
    B->Top = 200;
    B->Visible = true;
    BallTimer->Enabled = true;

    numberOfBounces = 0;

    Button1->Visible = false;
    Button2->Visible = false;
    Label1->Visible = false;
    Label2->Visible = false;
    Label3->Visible = false;

    sndPlaySound("snd/start.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    Button1->Visible = true;
    Button2->Visible = false;
    Label1->Visible = true;
    Label2->Visible = false;
    Label3->Visible = false;
}
//---------------------------------------------------------------------------
