/**********************************************************************************
// Breakout (C�digo Fonte)
// 
// Cria��o:     26 Mar 2012
// Atualiza��o: 20 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Uso da classe Scene para gerenciar objetos e tratar colis�o
//
**********************************************************************************/

#include "Engine.h"
#include "Breakout.h"
#include "Resources.h"
#include "Player.h"
#include "Block.h"
#include "Ball.h"
#include "Lost.h"
#include "Won.h"
#include <random>

// ------------------------------------------------------------------------------
// Inicializa��o de membros est�ticos da classe

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
    // posi��o dos blocos

    float line = 50.0f;
    float column = -320.0f;

    // -----------------------------------------
    // linha de blocos 

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 5);

    Block* block;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            block = new Block((Color)dist(gen));
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
    
    // habilita/desabilita visualiza��o de sprites
    if (ctrlKeyS && window->KeyDown('S'))
    {
        viewScene = !viewScene;
        ctrlKeyS = false;
    }
    else if (window->KeyUp('S'))
    {
        ctrlKeyS = true;
    }    

    // habilita/desabilita visualiza��o da bounding box
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

    // detec��o e resolu��o de colis�o
    scene->CollisionDetection();

    if (window->KeyDown(VK_RETURN))
        Engine::Next<Lost>();

    if (window->KeyDown('W'))
        Engine::Next<Won>();
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

