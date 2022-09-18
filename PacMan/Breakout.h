/**********************************************************************************
// Breakout (Arquivo de Cabe�alho)
//
// Cria��o:     26 Mar 2012
// Atualiza��o: 20 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Uso da classe Scene para gerenciar objetos e tratar colis�o
//
**********************************************************************************/

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Resources.h"

// ------------------------------------------------------------------------------
// Tipos dos objetos do jogo

enum ObjTypes
{
    PLAYER,                             // jogador
    BALL,                               // bola
    BLOCK                               // bloco
};

// ------------------------------------------------------------------------------

class Breakout : public Game
{
private:
    Sprite * backg = nullptr;           // plano de fundo

    bool viewScene = true;              // visualiza sprites da cena
    bool viewBBox  = false;             // visualiza bounding box
    bool ctrlKeyS  = true;              // controla pressionamento da tecla S
    bool ctrlKeyB  = true;              // controla pressionamento da tecla B

public:
    static Scene * scene;               // cena do jogo
    static Image * imgList[6];
    Image * heart;
    Sprite* life[3];
    
    static bool lost;                   
    static int lives;                   //n� de vidas

    void Init();                        // inicializa��o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
    void Finalize();                    // finaliza��o
};

// ------------------------------------------------------------------------------
