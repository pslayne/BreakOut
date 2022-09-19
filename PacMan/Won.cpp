#include "Won.h"
#include "Engine.h"
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

    // voltar para Home
    if (ctrlKeySPA && window->KeyDown(VK_SPACE))
    {
        Engine::Next<Home>();
        ctrlKeySPA = false;
    }
    else if (window->KeyUp(VK_SPACE))
    {
        ctrlKeySPA = true;
    }
}

// ------------------------------------------------------------------------------

void Won::Draw()
{
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}