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
#include "Ball.h"
#include "Lost.h"
#include "Won.h"
#include <random>

// ------------------------------------------------------------------------------
// Inicialização de membros estáticos da classe

Scene * Breakout::scene = nullptr;
Image * Breakout::imgList[6];

bool Breakout::lost = false;
int Breakout::lives = 3;

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
    // carregando imgs dos blocos
    Breakout::imgList[0] = new Image("Resources/BBlu.png");
    Breakout::imgList[1] = new Image("Resources/BGra.png");
    Breakout::imgList[2] = new Image("Resources/BGre.png");
    Breakout::imgList[3] = new Image("Resources/BPur.png");
    Breakout::imgList[4] = new Image("Resources/BRed.png");
    Breakout::imgList[5] = new Image("Resources/BYel.png");

    Block::imgList = Breakout::imgList;

    // -----------------------------------------
    // posição dos blocos
    float line = 80.0f;
    float column = -320.0f;
    
    // gerando semente para criação dos dos blocos
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 5);

    // adicionando os blocos
    int n_lines = 8;
    int n_columns = 9;
    Block* block;
    for (int i = 0; i < n_lines; i++) {
        for (int j = 0; j < n_columns; j++) {
            block = new Block((Color)dist(gen));
            block->MoveTo(window->CenterX() + column, line);
            scene->Add(block, STATIC);
            column += 80;
        }
        line += 30.0f;
        column = -320.0f;
    }

    heart = new Image("Resources/life.png");

    for (int i = 0; i < lives; i++) 
        life[i] = new Sprite(heart);
    
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

    // detecção e resolução de colisáo
    scene->CollisionDetection();

    //checa se acabaram os blocos
    if (window->KeyDown('W') || scene->Size() == (uint)2)
        Engine::Next<Won>();

    if (window->KeyDown('L') || lost)
        Engine::Next<Lost>();
} 

// ------------------------------------------------------------------------------

void Breakout::Draw()
{
    // desenha a cena
    if (viewScene)
    {
        backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);

        float x = 850.0f;
        float y = 40.0f;
        for (int i = 0; i < lives; i++) {
            life[i]->Draw(x, y, Layer::FRONT);
            x += life[i]->Width() + 10;
        }

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
    // apaga as imgs
    for (int i = 0; i < 6; i++)
        delete Breakout::imgList[i];

    delete heart;

    for (int i = 0; i < 3; i++)
        delete life[i];

    // apaga sprite
    delete backg;

    //apaga a cena
    delete scene;
}

