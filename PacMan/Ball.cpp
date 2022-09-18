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


// ---------------------------------------------------------------------------------

Ball::Ball(Player * p)
{
    // guarda jogador
    player = p;

    // cria sprite da bola
    sprite  = new Sprite("Resources/Ball.png");
    BBox(new Circle(sprite->Height()/2));

    // tamanho do player � 100x20
    MoveTo(player->X(), player->Y() - 17, Layer::FRONT);

    // velocidades iniciais
    velX = 100.0f;
    velY = -100.0f;

    // taxa de atualização de velocidade inicial
    velTax = 1.03f;

    // tipo do objeto
    type = BALL;
}

// ---------------------------------------------------------------------------------

Ball::~Ball()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Ball::OnCollision(Object * obj)
{
    // bola colide com bloco
    if (obj->Type() == BLOCK) {
        Rect* box = (Rect*) obj->BBox();
        
        if (x < box->Left() || x > box->Right())
            velX = -velX;
        if (y < box->Top() || y > box->Bottom())
            velY = -velY;

        if (velTax != 1.01 && abs(velX) >= 200.0f) velTax = 1.01;
        if (velTax != 1.005 && abs(velX) >= 350.0f) velTax = 1.005;
        if (velTax != 1 && abs(velX) >= 400.0f) velTax = 1;

        velX *= velTax;
        velY *= velTax;
    }

    // experimente deixar o bloco cair em vez de remov�-lo da cena
        //((Block*) obj)->velY = 200.0f;
}

// ---------------------------------------------------------------------------------

void Ball::Update()
{
    if (player->state == PLAYING)
    {
        Translate(velX * gameTime, velY * gameTime);

        if (y + sprite->Height() > window->Height())
            player->state = STOPED;
    }
    else
    {
        // mova para posi��o acima do player e o acompanhe
        MoveTo(player->X(), player->Y() - 17, Layer::FRONT);
    }

    // mantem a bola dentro da tela
    if (x - sprite->Width()/2 < 0)
    {
        MoveTo(float(sprite->Width() / 2), y);
        velX = -velX;
    }
    if (x + sprite->Width()/2 > window->Width())
    {
        MoveTo(float(window->Width() - sprite->Width() / 2), y);
        velX = -velX;
    }
    if (y - sprite->Height() / 2 < 0)
    {
        MoveTo(x, float(sprite->Height() / 2));
        velY = -velY;
    }

    //verifica se a bola caiu
    if (y + sprite->Height() /* / 2*/ > window->Height())
    {
        /*MoveTo(x, float(window->Height() - sprite->Height() / 2));
        velY = -velY;*/

        if (Breakout::lives > 1) 
            Breakout::lives -= 1;
        else {
            Breakout::scene->Delete();
            Breakout::lost = true;
        }
    }

    stringstream text;            // fluxo de texto para mensagens
    text << std::fixed;           // sempre mostra a parte fracionária
    text.precision(2);            // três casas depois da vírgula

    text << window->Title().c_str() << "         "
        << "vel = " << abs(velX);

    SetWindowText(window->Id(), text.str().c_str());
}

// ---------------------------------------------------------------------------------
