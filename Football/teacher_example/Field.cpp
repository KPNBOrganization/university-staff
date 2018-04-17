#include <vcl.h>
#include "Field.h"
#include "Form.h"

extern TForm1 *Form1;

Field::Field()
{
  aCanvas = Form1->FieldImage->Canvas;

  fieldRect = new TRect(0, 0,
                        Form1->FieldImage->Width,
                        Form1->FieldImage->Height);
  h = fieldRect->Height();
  w = fieldRect->Width();
  x_c = w/2;
  y_c = h/2;
}

void Field::draw()
{
  aCanvas->Brush->Color = clGreen;
  aCanvas->Brush->Style = bsSolid;
  aCanvas->FillRect(*fieldRect);
  drawLines();
}

void Field::drawLines()
{
  aCanvas->Brush->Style = bsClear;
  aCanvas->Pen->Color = clWhite;
  aCanvas->Rectangle(*fieldRect);
  aCanvas->MoveTo(x_c, fieldRect->bottom-1);
  aCanvas->LineTo(x_c, fieldRect->top);
  aCanvas->Ellipse(x_c-45, y_c-45, x_c+45, y_c+45);
  aCanvas->Brush->Color = clWhite;
  aCanvas->Ellipse(x_c-2, y_c-2, x_c+2, y_c+2);
}

bool Field::isInside(int x, int y)
{
return x >= fieldRect->left && x <= fieldRect->right && y >= fieldRect->top && y <= fieldRect->bottom;
}

bool Field::isOutSide(int x, int y)
{
return y < fieldRect->top || y > fieldRect->bottom;
}

bool Field::isOutLeft(int x, int y)
{
return x < fieldRect->left ;
}

bool Field::isOutRight(int x, int y)
{
return x > fieldRect->right;
}


