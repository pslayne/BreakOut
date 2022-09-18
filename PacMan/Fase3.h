#include "Breakout.h"
#include "Engine.h"
#include "Won.h"

class Fase3 : public Breakout
{
public:
	Fase3();
	
	void NextFase()
	{
		Engine::Next<Won>();
	};   // passa para o próximo nível
};