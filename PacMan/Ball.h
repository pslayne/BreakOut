/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Dez 2012
// Atualiza��o: 20 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Bola do jogo Breakout
//
**********************************************************************************/

#ifndef _BREAKOUT_BALL_H_
#define _BREAKOUT_BALL_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Player.h"                     // jogador do Breakout

// ---------------------------------------------------------------------------------

enum PLAYERSTATE { PLAYING, STOPED };

class Ball : public Object
{
private:
    Player * player;                    // ponteiro para jogador
    //Sprite * sprite;                    // sprite da bola
    uint state;                         // estado da bola
    bool ctrlKey = false;                // ctrl de tecla

public:
    float velX;                         // velocidade horizontal
    float velY;                         // velocidade vertical    
    float velTax;                       // taxa de atualiza��o da velocidade

    static uint numBalls;               // quantidade de bolas
    static uint maxBalls;               // quant m�xima de bolas

    Ball(Player * p);                   // construtor
    ~Ball();                            // destrutor
    float Width();                      // largura da bola
    float Height();                     // altura da bola

    void OnCollision(Object * obj);     // tratamento de colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline float Ball::Width()
{ return float(sprite->Width()); }

inline float Ball::Height()
{ return float(sprite->Height()); }

inline void Ball::Draw()
{ sprite->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif