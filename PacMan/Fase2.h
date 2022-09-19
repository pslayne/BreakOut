#include "Breakout.h"
#include "Engine.h"
#include "Fase3.h"

class Fase2 : public Breakout
{
public:
	Fase2();

	void NextFase()					// passa para o próximo nível
	{ Engine::Next<Fase3>(); };
};