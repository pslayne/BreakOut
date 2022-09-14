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

#ifndef _BREAKOUT_BLOCK_H_
#define _BREAKOUT_BLOCK_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"              // tipos específicos da engine
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

    void OnCollision(Object* obj);  // tratamento de colisão
    void Update();                  // atualização do objeto
    void Draw();                    // desenho do objeto 
};

inline void Block::Draw()
{ Img()->Draw(x, y, z); }

#endif