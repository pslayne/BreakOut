#include "Breakout.h"
#include "Engine.h"
#include "Won.h"

class Fase3 : public Breakout
{
public:
	Fase3();
	
	void NextFase()					// passa para o próximo nível
	{ Engine::Next<Won>(); };
};