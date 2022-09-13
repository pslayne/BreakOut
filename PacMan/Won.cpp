#include "Engine.h"
#include "Won.h"
#include "Breakout.h"

// ------------------------------------------------------------------------------

void Won::Init()
{
    backg = new Sprite("Resources/won.png");
}

// ------------------------------------------------------------------------------

void Won::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void Won::Update()
{
    // sai do jogo com a tecla ESC
    if (ctrlKeyESC && window->KeyDown(VK_ESCAPE))
    {
        ctrlKeyESC = false;
        window->Close();
    }
    else if (window->KeyUp(VK_ESCAPE))
    {
        ctrlKeyESC = true;
    }

    // volta pra Won com ENTER
    if (window->KeyDown(VK_RETURN))
        Engine::Next<Won>();
}

// ------------------------------------------------------------------------------

void Won::Draw()
{
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}