#include "Breakout.h"
#include "Engine.h"
#include "Fase3.h"

class Fase2 : public Breakout
{
public:
	Fase2();

	void NextFase()					// passa para o pr�ximo n�vel
	{ Engine::Next<Fase3>(); };
};