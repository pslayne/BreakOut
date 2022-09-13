#include "Engine.h"
#include "Won.h"
#include "Home.h"

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

    // volta pra Home
    if (window->KeyDown('H'))
        Engine::Next<Home>();
}

// ------------------------------------------------------------------------------

void Won::Draw()
{
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}