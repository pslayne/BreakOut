/**********************************************************************************
// Block (Arquivo de Cabeçalho)
// 
// Criação:     22 Dez 2012
// Atualização: 20 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Bloco do jogo Breakout
//
**********************************************************************************/

#include "Block.h"
#include "Breakout.h"
#include <random>
#include <sstream>
using std::stringstream;


// ---------------------------------------------------------------------------------
Block::Block() {
    // sprites dos blocos
    gray = new Sprite("Resources/Tile1.png");
    red = new Sprite("Resources/Tile2.png");
    purple = new Sprite("Resources/Tile3.png");
    blue = new Sprite("Resources/Tile4.png");
    yellow = new Sprite("Resources/Tile5.png");
    green = new Sprite("Resources/Tile6.png");

    //bounding box - cada bloco tem dimensões 60x17
    BBox(new Rect(-30, -8.5, 30, 8.5));

    // velocidades iniciais
    velX = 0.0f;
    velY = 0.0f;

    // tipo do objeto
    type = BLOCK;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 5);
    color = (Color)dist(gen);
    
    /*stringstream text;
    text << "color: " << color << "\n";

    OutputDebugString(text.str().c_str());*/
}

// ---------------------------------------------------------------------------------

Block::~Block()
{
    delete gray;
    delete red;
    delete purple;
    delete blue;
    delete yellow;
    delete green;

}

// ---------------------------------------------------------------------------------

void Block::Update()
{
    // desloca o bloco
    Translate(velX * gameTime, velY * gameTime);

    // destrói ao sair da janela
    if (y > window->Height())
        Breakout::scene->Delete();
}

void Block::Draw() {
    if (color == Color::gray) gray->Draw(x, y, z);
    else if (color == Color::red) red->Draw(x, y, z);
    else if (color == Color::purple) purple->Draw(x, y, z);
    else if (color == Color::blue) blue->Draw(x, y, z);
    else if (color == Color::yellow) yellow->Draw(x, y, z);
    else green->Draw(x, y, z);

}

// ---------------------------------------------------------------------------------
