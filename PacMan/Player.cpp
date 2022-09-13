/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:     22 Dez 2012
// Atualização: 20 Ago 2021
// Compilador:  Visual C++ 14
//
// Descrição:   Player do jogo Breakout
//
**********************************************************************************/

#include "Breakout.h"
#include "Player.h"
#include "Ball.h"

// ---------------------------------------------------------------------------------

Player::Player() {
    // sprite do jogador
    sprite = new Sprite("Resources/Player.png");

    //bounding box
    BBox(new Rect(-sprite->Width()/2, -sprite->Height() / 2, sprite->Width() / 2, sprite->Height() / 2));

    // centraliza o jogador
    MoveTo(window->CenterX(), 
           window->Height() - 30.0f, 
           Layer::FRONT);

    // velocidade do jogador
    vel = 500; 

    // estado inicial do jogo
    state = STOPED;

    // tipo do objeto
    type = PLAYER;

}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    // bola colidiu com o player
    if (obj->Type() == BALL)
    {
        Ball * ball = (Ball*) obj;
        ball->velY = -ball->velY;
    }    
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // inicia o jogo com barra de espaço
    if (state == STOPED && window->KeyDown(VK_SPACE))
        state = PLAYING;

    // desloca jogador horizontalmente
    if (window->KeyDown(VK_RIGHT))
        Translate(vel * gameTime, 0);
    if (window->KeyDown(VK_LEFT))
        Translate(-vel * gameTime, 0);

    // mantém jogador dentro da janela (tam. da barra: 100x20)
    if (x - sprite->Width() / 2 < 0)
        MoveTo(sprite->Width() / 2, y);
    if (x + sprite->Width() / 2 > window->Width())
        MoveTo(window->Width() - sprite->Width() / 2, y);
}

// ---------------------------------------------------------------------------------
