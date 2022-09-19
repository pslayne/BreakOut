#ifndef _SKYBREAK_WON_H_
#define _SKYBREAK_WON_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Won : public Game
{
private:
    Sprite* backg = nullptr;        // pano de fundo
    bool ctrlKeyESC = false;        // controle do ESC
    bool ctrlKeySPA = false;        // controle do SPACE

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// -----------------------------------------------------------------------------

#endif