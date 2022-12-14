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
    vel = 700; 

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
    if (obj->Type() == BALL) {
        //Rect* player = (Rect*)BBox();
        Ball * ball = (Ball*) obj;

        ball->velY = -ball->velY;
        ball->MoveTo(ball->X(), y - 17);
    }    
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // desloca jogador horizontalmente
    if (window->KeyDown(VK_RIGHT))
        Translate(vel * gameTime, 0);
    if (window->KeyDown(VK_LEFT))
        Translate(-vel * gameTime, 0);

    // mant�m jogador dentro da janela (tam. da barra: 100x20)
    if (x - Img()->Width() / 2 < 0)
        MoveTo((float)Img()->Width() / 2, y);
    if (x + Img()->Width() / 2 > window->Width())
        MoveTo((float)window->Width() - Img()->Width() / 2, y);
}

// ---------------------------------------------------------------------------------
