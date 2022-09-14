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
    velX = 300.0f;
    velY = -300.0f;

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

    // mant�m a bola dentro da tela (tam. da bola: 12x12)
    if (x < 0)
    {
        MoveTo(0.0f, y);
        velX = -velX;
    }
    if (x + sprite->Width() > window->Width())
    {
        MoveTo(float(window->Width() - sprite->Width()), y);
        velX = -velX;
    }
    if (y < 0)
    {
        MoveTo(x, 0.0f);
        velY = -velY;
    }
    if (y + sprite->Height() > window->Height())
    {
        /*MoveTo(x, float(window->Height() - sprite->Height()));
        velY = -velY;*/

        Breakout::lost = true;
    }
}

// ---------------------------------------------------------------------------------
