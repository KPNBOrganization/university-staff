//---------------------------------------------------------------------------
#ifndef FormH
#define FormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
#define PI 3.1415926535897932385

class Ball;
class Field;

class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TImage *FieldImage;
        void __fastcall StartClick(TObject *Sender);
        void __fastcall StopClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
        Ball* ball;
        Field* field;
        __fastcall TForm1(TComponent* Owner);
   void __fastcall Simulate(TObject*, bool&);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
