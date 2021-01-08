
#include <iostream>
#include "general/Logger.h"
#include "general/filesystem.h"
#include "physics/PhysicsComponent.h"
#include "graphics/GraphicsSystem.h"
#include "graphics/ParticleManager.h"


int main(int argc, char** argv)
{
	std::cout << "Hello world!\n";
	std::cout << getCurrentWorkingDir() << "\n";
	Logger* logger = new Logger(getCurrentWorkingDir());

    Logger::log("Starting");
	graphics::GraphicsSystem* gfx = new graphics::GraphicsSystem("test", 512, 512, graphics::WindowMode::WINDOW_MODE_WINDOWED);

	physics::PhysicsComponent* phys = new physics::PhysicsComponent({ 0, 0 }, { 1, 1 }, { 1, 1 }, { 1, 1 });

	Uint32 time = SDL_GetTicks();

	graphics::Texture reimu = gfx->loadTexture(getDataFile("sprite.png"));
	
	
	graphics::ParticleManager* particleManager = new graphics::ParticleManager(256);
	
	for (int index = 0; index < 15; ++index)
	{
		particleManager->create({static_cast<double>(3 * index + 1), 3}, {0, 0}, {0, 2}, {255, 255, 255, 255}, {2, 2}, 256);
	}

	while (true)
	{
		ticks_t newTime = SDL_GetTicks();
		ticks_t delay = newTime - time;
		time = newTime;

		if (delay < 16)
			SDL_Delay(16 - delay);
		
		SDL_Event* event;
		SDL_PollEvent(event); //currently only here to keep window visible on mac

		phys->update(16);

		gfx->renderTexture(reimu, Vector2Int{ static_cast<int>(phys->getPosition().x), static_cast<int>(phys->getPosition().y) });

		gfx->update();

	}

	Logger::close();
	return 0;
}
