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

Image** Block::imgList = nullptr;

// ---------------------------------------------------------------------------------
Block::Block(Color co) {
    // bounding box - cada bloco tem dimensões 60x17
    BBox(new Rect(60, 17));

    // tipo do objeto
    type = BLOCK;
    spriteChange = false;

    // velocidades sempre nulas
    velX = 0.0f;
    velY = 0.0f;

    // sprite do bloco
    Img(new Sprite(Block::imgList[co]));
    
    // cor do bloco
    color = co;

    // OutputDebugString(text.str().c_str());
}

// ---------------------------------------------------------------------------------

Block::~Block()
{

}

// ---------------------------------------------------------------------------------

void Block::Update()
{
    // desloca o bloco
    //Translate(velX * gameTime, velY * gameTime);

    // altera a Spite
    if (spriteChange) {
        Img(new Sprite(Block::imgList[color]));
        spriteChange = false;
    }
}

// ---------------------------------------------------------------------------------

void Block::OnCollision(Object * obj)
{
    if (obj->Type() == BALL)
    {
        switch (color) {
            case Color::gray:   color = Color::red;     break;
            case Color::red:    color = Color::purple;  break;
            case Color::purple: color = Color::blue;    break;
            case Color::blue:   color = Color::yellow;  break;
            case Color::yellow: color = Color::green;   break;
            case Color::green:  Breakout::scene->Delete(this, STATIC);
        }

        spriteChange = true;
    }
}
