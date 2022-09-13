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

#ifndef _BREAKOUT_BLOCK_H_
#define _BREAKOUT_BLOCK_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"              // tipos espec�ficos da engine
#include "Object.h"             // interface de Object
#include "Sprite.h"             // interface de Sprites

enum Color {gray, red, purple, blue, yellow, green};

// ---------------------------------------------------------------------------------

class Block : public Object
{
private:
    // sprites do bloco
    Sprite * gray;
    Sprite * red;
    Sprite * purple;
    Sprite * blue;
    Sprite * yellow;
    Sprite * green;

    //ponteiros para as imagens
    static Image * grayImg;
    static Image * redImg;
    static Image * purpleImg;
    static Image * blueImg;
    static Image * yellowImg;
    static Image * greenImg;

public:
    float velX;                 // velocidade horizontal
    float velY;                 // velocidade vertical

    Block();         // construtor
    ~Block();                   // destrutor

    void Update();              // atualiza��o do objeto
    void Draw();                // desenho do objeto

    Color color;
};

#endif