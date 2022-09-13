/**********************************************************************************
// Breakout (Código Fonte)
// 
// Criação:     26 Mar 2012
// Atualização: 20 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Uso da classe Scene para gerenciar objetos e tratar colisão
//
**********************************************************************************/

#include "Engine.h"
#include "Breakout.h"
#include "Resources.h"
#include "Player.h"
#include "Block.h"
#include "Ball.h"

// ------------------------------------------------------------------------------
// Inicialização de membros estáticos da classe

Scene * Breakout::scene = nullptr;

// ------------------------------------------------------------------------------

void Breakout::Init()
{
    // cena do jogo
    scene = new Scene();

    // carrega background
    backg = new Sprite("Resources/Background.png");
    
    // ---------------------------
    // cria jogador
    Player * player = new Player();
    scene->Add(player, MOVING);

    // ---------------------------
    // cria bola

    Ball * ball = new Ball(player);
    scene->Add(ball, MOVING);

    // -----------------------------------------
    // posição dos blocos

    float line = 50.0f;
    float column = -320.0f;
    

    // -----------------------------------------
    // linha de blocos    

    Block* block;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            block = new Block();
            block->MoveTo(window->CenterX() + column, line);
            scene->Add(block, STATIC);

            column += 80;
        }

        line += 30.0f;
        column = -320.0f;
    }
}

// ------------------------------------------------------------------------------

void Breakout::Update()
{
    // sai com o pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();
    
    // habilita/desabilita visualização de sprites
    if (ctrlKeyS && window->KeyDown('S'))
    {
        viewScene = !viewScene;
        ctrlKeyS = false;
    }
    else if (window->KeyUp('S'))
    {
        ctrlKeyS = true;
    }    

    // habilita/desabilita visualização da bounding box
    if (ctrlKeyB && window->KeyDown('B'))
    {
        viewBBox = !viewBBox;
        ctrlKeyB = false;
    }
    else if (window->KeyUp('B'))
    {
        ctrlKeyB = true;
    }

    // atualiza objetos da cena
    scene->Update();

    // detecção e resolução de colisão
    scene->CollisionDetection();
} 

// ------------------------------------------------------------------------------

void Breakout::Draw()
{
    // desenha a cena
    if (viewScene)
    {
        backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
        scene->Draw();
    }

    // desenha a bounding box de todos os objetos
    if (viewBBox)
    {
        scene->DrawBBox();
    }
} 

// ------------------------------------------------------------------------------

void Breakout::Finalize()
{
    // apaga sprite
    delete backg;

    //apaga a cena
    delete scene;

    //apaga as imagens
    /*delete grayTile;
    delete redTile;
    delete purpleTile;
    delete blueTile;
    delete yellowTile;
    delete greenTile;*/
}

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura a janela
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 540);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Breakout");
    engine->window->Icon(IDI_ICON);
    //engine->window->Cursor(IDC_CURSOR);

    // configura dispositivo gráfico
    //engine->graphics->VSync(true);
    
    // inicia jogo
    int status = engine->Start(new Breakout());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

