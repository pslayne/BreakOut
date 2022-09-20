/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
//
// Cria��o:     22 Dez 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Bola do jogo Breakout
//
**********************************************************************************/

#include "Ball.h"
#include "Block.h"
#include "Breakout.h"
#include <cmath>
using std::abs;
#include <sstream>
using std::stringstream;

uint Ball::numBalls = 0;
uint Ball::maxBalls;

// ---------------------------------------------------------------------------------

Ball::Ball(Player *p)
{
    // guarda jogador
    player = p;

    // bola parada
    state = STOPED;

    // cria sprite da bola
    Img(new Sprite("Resources/Ball.png"));
    BBox(new Circle(Img()->Height() / 2));

    // tamanho do player � 100x20
    MoveTo(player->X(), player->Y() - 17, Layer::FRONT);

    // velocidades iniciais
    velX = 100.0f;
    velY = -100.0f;

    // taxa de atualização de velocidade inicial
    velTax = 1.03f;

    // tipo do objeto
    type = BALL;

    // adiciona uma bola no total
    numBalls++;
}

// ---------------------------------------------------------------------------------

Ball::~Ball()
{
    delete sprite;
    numBalls--;
}

// ---------------------------------------------------------------------------------

void Ball::OnCollision(Object *obj)
{
    // bola colide com bloco
    if (obj->Type() == BLOCK)
    {
        Rect *box = (Rect *)obj->BBox();

        if (x < box->Left() || x > box->Right())
            velX = -velX;
        if (y < box->Top() || y > box->Bottom())
            velY = -velY;

        if (velTax != 1.01 && abs(velX) >= 150.0f)
            velTax = 1.01;
        if (velTax != 1.005 && abs(velX) >= 250.0f)
            velTax = 1.005;
        if (velTax != 1 && abs(velX) >= 300.0f)
            velTax = 1;

        velX *= velTax;
        velY *= velTax;
    }
}

// ---------------------------------------------------------------------------------

void Ball::Update()
{
    // inicia movimento da bola
    if (ctrlKey && window->KeyDown(VK_SPACE))
    {
        state = PLAYING;
        if (numBalls < maxBalls)
        {
            Ball *newBall = new Ball(player);
            Breakout::scene->Add(newBall, MOVING);
        }
        ctrlKey = false;
    }
    else if (window->KeyUp(VK_SPACE))
    {
        ctrlKey = true;
    }

    if (state == PLAYING)
    {
        Translate(velX * gameTime, velY * gameTime);
    }
    else
    {
        // mova para posi��o acima do player e o acompanhe
        MoveTo(player->X(), player->Y() - 17, Layer::FRONT);
    }

    // mantem a bola dentro da tela
    if (x - Img()->Width() / 2.f < 0)
    {
        MoveTo(Img()->Width() / 2.f, y);
        velX = -velX;
    }
    if (x + Img()->Width() / 2.f > window->Width())
    {
        MoveTo(window->Width() - Img()->Width() / 2.f, y);
        velX = -velX;
    }
    if (y - Img()->Height() / 2 < 0)
    {
        MoveTo(x, Img()->Height() / 2.f);
        velY = -velY;
    }

    // verifica se a bola caiu
    if (y + Img()->Height() > window->Height())
    {
        if (numBalls <= maxBalls)
        {
            // parar o objeto
            state = STOPED;

            // reseta as velocidades
            velX = 100.0f;
            velY = -100.0f;
        }
        Breakout::lives--;
    }

    stringstream text;  // fluxo de texto para mensagens
    text << std::fixed; // sempre mostra a parte fracionária
    text.precision(2);  // três casas depois da vírgula

    text << window->Title().c_str() << "         "
         << "vel = " << abs(velX);

    SetWindowText(window->Id(), text.str().c_str());
}

// ---------------------------------------------------------------------------------
