//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Football0.res");
USEFORM("Form.cpp", Form1);
USEUNIT("Field.cpp");
USEUNIT("Ball.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
