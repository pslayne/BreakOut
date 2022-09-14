/**********************************************************************************
// Player (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Dez 2012
// Atualiza��o: 20 Ago 2021
// Compilador:  Visual C++ 14
//
// Descri��o:   Player do jogo Breakout
//
**********************************************************************************/

#include "Breakout.h"
#include "Player.h"
#include "Ball.h"

// ---------------------------------------------------------------------------------

Player::Player() {
    // sprite do jogador
    Img(new Sprite("Resources/Player.png"));

    //bounding box
    BBox(new Rect(Width(), Height()));

    // centraliza o jogador
    MoveTo(window->CenterX(), 
           window->Height() - 30.0f, 
           Layer::FRONT);

    // velocidade do jogador
    vel = 600; 

    // estado inicial do jogo
    state = STOPED;

    // tipo do objeto
    type = PLAYER;

}

// ---------------------------------------------------------------------------------

Player::~Player()
{

}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    // bola colidiu com o player
    if (obj->Type() == BALL)
    {
        Ball * ball = (Ball*) obj;
        ball->MoveTo(ball->X(), y - 17);
        ball->velY = -ball->velY;
    }    
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // inicia o jogo com barra de espa�o
    if (state == STOPED && window->KeyDown(VK_SPACE))
        state = PLAYING;

    // desloca jogador horizontalmente
    if (window->KeyDown(VK_RIGHT))
        Translate(vel * gameTime, 0);
    if (window->KeyDown(VK_LEFT))
        Translate(-vel * gameTime, 0);

    // mant�m jogador dentro da janela (tam. da barra: 100x20)
    if (x - Img()->Width() / 2 < 0)
        MoveTo(Img()->Width() / 2, y);
    if (x + Img()->Width() / 2 > window->Width())
        MoveTo(window->Width() - Img()->Width() / 2, y);
}

// ---------------------------------------------------------------------------------
