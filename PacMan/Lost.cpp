#include "Engine.h"
#include "Lost.h"
#include "Breakout.h"

// ------------------------------------------------------------------------------

void Lost::Init()
{
    backg = new Sprite("Resources/lost.png");
}

// ------------------------------------------------------------------------------

void Lost::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void Lost::Update()
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

    // volta pra Lost com ENTER
    if (window->KeyDown(VK_RETURN))
        Engine::Next<Lost>();
}

// ------------------------------------------------------------------------------

void Lost::Draw()
{
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

