/**********************************************************************************
// Home (Código Fonte) 
// 
// Criação:     18 Jan 2013
// Atualização: 25 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "Breakout.h"

// ------------------------------------------------------------------------------

void Home::Init()
{
    backg = new Sprite("Resources/breakout.png");
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void Home::Update()
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

    // passa ao primeiro nível com ENTER
    if (window->KeyDown(VK_SPACE)) {
        Breakout::lost = false;
        Engine::Next<Breakout>();
    }
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine* engine = new Engine();

    // configura a janela do jogo
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 540);
    engine->window->Color(0, 0, 0);
    engine->window->Title("SkyOut");
    engine->window->Icon(IDI_ICON);

    // configura dispositivo gráfico
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new Home());

    delete engine;
    return status;
}