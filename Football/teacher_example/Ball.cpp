#include <vcl.h>
#include <math.h>
#include "Ball.h"
#include "Field.h"
#include "Form.h"

extern TForm1 *Form1;

Ball::Ball()
{
        aCanvas = Form1->FieldImage->Canvas;
        r = 4;
        color = clYellow;
        speed = 0;
        slowdown = 1;
        dir = 0;
}


void Ball::draw()
{
  aCanvas->Pen->Color = color;
  aCanvas->Brush->Color = color;
  aCanvas->Brush->Style = bsSolid;
  aCanvas->Ellipse(x-r, y-r, x+r, y+r);
}

void Ball::move()
{
        if (speed==0) return;
        bool is_in = Form1->field->isInside(x, y);

        x += speed*cos(dir);
        y -= speed*sin(dir);
        speed = speed<slowdown ? 0 : speed-slowdown;

        bool will_be_in = Form1->field->isInside(x, y);

        if (is_in && !will_be_in){
                if (Form1->field->isOutRight(x, y) ||
                    Form1->field->isOutLeft(x, y)) dir = PI - dir;
                else dir = - dir;
        }
}
