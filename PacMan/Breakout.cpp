/**********************************************************************************
// Breakout (Cádigo Fonte)
//
// Criação:     26 Mar 2012
// Atualização: 20 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Uso da classe Scene para gerenciar objetos e tratar colisáo
//
**********************************************************************************/

#include "Engine.h"
#include "Breakout.h"
#include "Resources.h"
#include "Player.h"
#include "Block.h"
#include "Heart.h"
#include "Lost.h"
#include "Won.h"
#include <random>

// ------------------------------------------------------------------------------
// Inicialização de membros estáticos da classe

Scene* Breakout::scene = nullptr;
Image* Breakout::imgBlockList[6];
Image* Breakout::imgLife;
uint Breakout::lives;

// ------------------------------------------------------------------------------

void Breakout::Init()
{
    // cena do jogo
    scene = new Scene();

    // carrega background
    backg = new Sprite("Resources/Background.png");

    // ---------------------------
    // cria jogador
    player = new Player();
    scene->Add(player, MOVING);

    // ---------------------------
    // cria bola
    Ball::maxBalls = maxBalls;
    Ball* ball = new Ball(player);
    scene->Add(ball, MOVING);

    // -----------------------------------------
    // cria blocos

    // carregando imgs dos blocos
    Breakout::imgBlockList[0] = new Image("Resources/BBlu.png");
    Breakout::imgBlockList[1] = new Image("Resources/BGra.png");
    Breakout::imgBlockList[2] = new Image("Resources/BGre.png");
    Breakout::imgBlockList[3] = new Image("Resources/BPur.png");
    Breakout::imgBlockList[4] = new Image("Resources/BRed.png");
    Breakout::imgBlockList[5] = new Image("Resources/BYel.png");
    Block::imgList = Breakout::imgBlockList;

    // posição dos blocos
    float line = 80.0f;
    float column = -320.0f;

    // gerando semente para criação dos dos blocos
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 5);

    // adicionando os blocos
    Block *block;
    for (uint i = 0; i < blockLines; i++)
    {
        for (uint j = 0; j < blockColumns; j++)
        {
            block = new Block((Color)dist(gen));
            block->MoveTo(window->CenterX() + column, line);
            scene->Add(block, STATIC);
            column += 80;
        }
        line += 30.0f;
        column = -320.0f;
    }

    // -----------------------------------------
    // cria lives
    Breakout::imgLife = new Image("Resources/life.png");
    Heart::img = Breakout::imgLife;

    Heart::finalPosition = lives;

    float heartX = 880.0f;

    Heart* heart;
    for (uint i = 0; i < lives; i++) {
        heart = new Heart(i);
        heart->MoveTo(heartX, 40.0f, Layer::FRONT);
        scene->Add(heart, STATIC);
        heartX -= 30.0f;
    }
}

// ------------------------------------------------------------------------------

void Breakout::Update()
{
    // sai com o pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // habilita/desabilita visualização de sprites
    if (ctrlKey['S'] && window->KeyDown('S'))
    {
        viewScene = !viewScene;
        ctrlKey['S'] = false;
    }
    else if (window->KeyUp('S'))
    {
        ctrlKey['S'] = true;
    }

    // habilita/desabilita visualização da bounding box
    if (ctrlKey['B'] && window->KeyDown('B'))
    {
        viewBBox = !viewBBox;
        ctrlKey['B'] = false;
    }
    else if (window->KeyUp('B'))
    {
        ctrlKey['B'] = true;
    }

    // passa para a próxima fase
    if (ctrlKey['W'] && window->KeyDown('W'))
    {
        NextFase();
        ctrlKey['W'] = false;
    }
    else if (window->KeyUp('W'))
    {
        ctrlKey['W'] = true;
    }

    // atualiza objetos da cena
    scene->Update();

    // detecção e resolução de colisáo
    scene->CollisionDetection();

    // checa se acabaram os blocos
    if (scene->SizeStatics() == lives)
        NextFase();

    // checa se o jogador ainda possui vidas
    if (lives < 1 || window->KeyDown('L'))
        Engine::Next<Lost>();
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
    // apaga as imgs dos blocos
    for (int i = 0; i < 6; i++)
        delete Breakout::imgBlockList[i];

    // apaga a img da life
    delete Breakout::imgLife;

    // apaga sprite
    delete backg;

    // apaga a cena
    delete scene;
}

// ------------------------------------------------------------------------------

void Breakout::NextFase()
{
}
