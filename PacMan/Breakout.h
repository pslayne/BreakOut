/**********************************************************************************
// Breakout (Arquivo de Cabeçalho)
//
// Criação:     26 Mar 2012
// Atualização: 20 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Uso da classe Scene para gerenciar objetos e tratar colisão
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

    void Init();                        // inicialização
    void Update();                      // atualização
    void Draw();                        // desenho
    void Finalize();                    // finalização

    /*const Image* grayTile = new Image("Resources/Tile1.png");
    const Image* redTile = new Image("Resources/Tile2.png");
    const Image* purpleTile = new Image("Resources/Tile3.png");
    const Image* blueTile = new Image("Resources/Tile4.png");
    const Image* yellowTile = new Image("Resources/Tile5.png");
    const Image* greenTile = new Image("Resources/Tile6.png");

    Image* grayTile();
    Image* redTile();
    Image* purpleTile();
    Image* blueTile();
    Image* yellowTile();
    Image* greenTile();*/
};

//inline Image* Breakout::grayTile() { return grayTile; }


// ------------------------------------------------------------------------------
