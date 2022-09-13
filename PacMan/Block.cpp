/**********************************************************************************
// Block (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Dez 2012
// Atualiza��o: 20 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Bloco do jogo Breakout
//
**********************************************************************************/

#include "Block.h"
#include "Breakout.h"

char imgBlokList[6][19] = {
        "Resources/BBlu.png",
        "Resources/BGra.png",
        "Resources/BGre.png",
        "Resources/BPur.png",
        "Resources/BRed.png",
        "Resources/BYel.png"
};

// ---------------------------------------------------------------------------------
Block::Block(Color co) {
    // bounding box - cada bloco tem dimens�es 60x17
    BBox(new Rect(60, 17));

    // tipo do objeto
    type = BLOCK;

    // velocidades sempre nulas
    velX = 0.0f;
    velY = 0.0f;

    // sprite do bloco
    Img(new Sprite(imgBlokList[co]));
    
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
    Translate(velX * gameTime, velY * gameTime);

    // destr�i ao sair da janela
    if (y > window->Height())
        Breakout::scene->Delete();
}

// ---------------------------------------------------------------------------------
