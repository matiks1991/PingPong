//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int xBall=8, yBall=8;

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

    if(B->Top-5 <= Background->Top) yBall=-yBall; //

    if(B->Top+B->Height >= Background->Height) yBall=-yBall;

    if (B->Left+B->Width >= P1->Left+P1->Width+15) //skucha P1
    {
        BallTimer->Enabled = false;
        B->Visible = false;
    }
    else if (B->Left <= P2->Left-15) //skucha P2
    {
        BallTimer->Enabled = false;
        B->Visible = false;
    }
    else if ((B->Top > (P1->Top-B->Height/2)) && (B->Top < P1->Top+P1->Height+B->Height/2) &&  //odbicie P1
    (B->Left+B->Width > P1->Left))
    {
        if(xBall>0) xBall=-xBall;
    }
    else if ((B->Top > (P2->Top-B->Height/2)) && (B->Top < P2->Top+P2->Height+B->Height/2) &&  //odbicie P2
    (B->Left < P2->Left+P2->Width))
    {
        if(xBall<0) xBall=-xBall;
    }
}
//---------------------------------------------------------------------------
