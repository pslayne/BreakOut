#include "Heart.h"
#include "Breakout.h"

uint Heart::finalPosition;
Image* Heart::img = nullptr;

Heart::Heart(uint pos)
{
    position = pos;

    // sprite do objeto
    Img(new Sprite(Heart::img));

    type = HEART;
}

void Heart::Update()
{
    finalPosition = Breakout::lives;

    if (position >= finalPosition)
    {
        Breakout::scene->Delete(this, STATIC);
    }
}
