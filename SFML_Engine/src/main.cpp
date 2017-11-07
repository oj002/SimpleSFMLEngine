#include "../SimpleSfmlEngine/engine.h"
#include "States/SplashState.h"
#include "DEFINITIONS.h"
#include <cmath>
#include <iostream>

int main()
{
	sse::Game(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE, [](sse::GameDataRef data) { data->machine.AddState(sse::StateRef(new sse::SplashState(data))); });
	

	//std::cin.get();
	return 0;
}