//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Form.h"
#include "Ball.h"
#include "Field.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner)
{
        field = new Field;
        field->draw();

        ball = new Ball;
        ball->moveTo(100,100);
        ball->draw();

        ball->setSpeed(40);
        ball->setDir(PI/4 -0.1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StartClick(TObject *Sender)
{
        Application->OnIdle = Simulate;
        Button1->Enabled = false;
        Button2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StopClick(TObject *Sender)
{
        Application->OnIdle = NULL;
        Button1->Enabled = true;
        Button2->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Simulate(TObject*, bool &done)
{
  ball->move();

  field->draw();
  ball->draw();

  ::Sleep(50);
  done = false;  //keeps loop going
}
