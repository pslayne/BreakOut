#ifndef _BREAKOUT_HEART_H_
#define _BREAKOUT_HEART_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                     // tipos específicos da engine
#include "Object.h"                    // interface de Object

// ---------------------------------------------------------------------------------

class Heart : public Object
{
private:
    uint position;                    // quant máxima de bolas
    
public:
    static uint finalPosition;
    static Image* img;

    Heart(uint pos);
    void Update();                     // atualização do objeto
    void Draw();
};

// ---------------------------------------------------------------------------------

inline void Heart::Draw()
{ Img()->Draw(x, y, z); }


#endif
