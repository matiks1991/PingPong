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
    TButton *Button1;
    TButton *Button2;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
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
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 