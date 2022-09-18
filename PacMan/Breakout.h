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
    bool ctrlKey[256] = {true};         // controla pressionamento das teclas

protected:
    int blockLines;                     // nº de linhas com blocos
    int blockColumns;                   // nº de colunas com blocos
    /*bool lost;                          
    int lives; */                         // quant de vidas
    virtual void NextFase();            // passa para a próxima fase

public:
    static Scene * scene;               // cena do jogo
    static Image * imgList[6];
    Image * heart;
    Sprite* life[3];

    static bool lost;
    static int lives;

    void Init();                        // inicializa��o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
    void Finalize();                    // finaliza��o
};

// ------------------------------------------------------------------------------

#endif