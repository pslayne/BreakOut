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

enum Color { blue, gray, green, purple, red, yellow };

// ---------------------------------------------------------------------------------

class Block : public Object
{
public:
    float velX;                     // velocidade horizontal
    float velY;                     // velocidade vertical
    Color color;                    // cor do bloco
    bool spriteChange;              // sprite do bloco vai ser alterado

    Block(Color co);                // construtor
    ~Block();                       // destrutor

    static Image** imgList;         // lista com as Images carregadas

    void OnCollision(Object* obj);  // tratamento de colis�o
    void Update();                  // atualiza��o do objeto
    void Draw();                    // desenho do objeto 
};

inline void Block::Draw()
{ Img()->Draw(x, y, z); }

#endif