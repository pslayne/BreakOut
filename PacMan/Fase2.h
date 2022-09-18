#include "Breakout.h"
#include "Engine.h"
#include "Fase3.h"

class Fase2 : public Breakout
{
public:
	Fase2();

	void NextFase()
	{
		Engine::Next<Fase3>();
	};   // passa para o próximo nível
};