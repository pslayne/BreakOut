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

#ifndef _BREAKOUT_H_
#define _BREAKOUT_H_

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Player.h"
#include "Ball.h"
#include "Resources.h"
#include <list>
using std::list;

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
    Player* player;

    bool viewScene = true;              // visualiza sprites da cena
    bool viewBBox  = false;             // visualiza bounding box
    bool ctrlKey[256] = {true};         // controla pressionamento das teclas

protected:
    uint blockLines;                    // nº de linhas com blocos
    uint blockColumns;                  // nº de colunas com blocos
    uint maxBalls;                      // nº max de bolas
    virtual void NextFase();            // passa para a próxima fase

public:
    static Scene * scene;               // cena do jogo
    static Image * imgList[6];
    static uint lives;                  // quantidade de vidas
    Image * heart;
    Sprite* life[5];

    void Init();                        // inicializa��o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
    void Finalize();                    // finaliza��o
};

// ------------------------------------------------------------------------------

#endif