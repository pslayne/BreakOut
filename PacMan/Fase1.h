#include "Breakout.h"
#include "Engine.h"
#include "Fase2.h"

class Fase1 : public Breakout
{
public:
	Fase1();                    // construtor

	void NextFase()
	{ Engine::Next<Fase2>(); }; // passa para o próximo nível
};
