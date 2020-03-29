
#include <iostream>
#include "general/Logger.h"
#include "general/filesystem.h"
#include "physics/PhysicsComponent.h"
#include "graphics/GraphicsSystem.h"


int main(int argc, char** argv)
{
	Logger* logger = new Logger(getCurrentWorkingDir());

    Logger::log("Starting");
	graphics::GraphicsSystem* gfx = new graphics::GraphicsSystem("test", 512, 512, graphics::WindowMode::WINDOW_MODE_WINDOWED);

	physics::PhysicsComponent* phys = new physics::PhysicsComponent({ 0, 0 }, { 1, 1 }, { 1, 1 }, { 1, 1 });

	Uint32 time = SDL_GetTicks();

	graphics::Texture reimu = gfx->loadTexture(getDataFile("reimuidle.png"));

	while (true)
	{
		Uint32 newTime = SDL_GetTicks();
		Uint32 delay = newTime - time;
		time = newTime;

		if (delay < 16)
			SDL_Delay(16 - delay);

		phys->update(16);

		gfx->renderTexture(reimu, Vector2Int{ static_cast<int>(phys->getPosition().x), static_cast<int>(phys->getPosition().y) });

		gfx->update();

	}

	Logger::close();
	return 0;
}
