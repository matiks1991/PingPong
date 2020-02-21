//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TShape *Background;
    TTimer *Paddle1_Up;
    TImage *P1;
    TImage *P2;
    TImage *B;
    TTimer *Paddle1_Down;
    TTimer *Paddle2_Up;
    TTimer *Paddle2_Down;
    TTimer *BallTimer;
    void __fastcall Paddle1_UpTimer(TObject *Sender);
    void __fastcall Paddle1_DownTimer(TObject *Sender);
    void __fastcall Paddle2_UpTimer(TObject *Sender);
    void __fastcall Paddle2_DownTimer(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall BallTimerTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 