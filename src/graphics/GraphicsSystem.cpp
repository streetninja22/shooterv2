#include "graphics/GraphicsSystem.h"

namespace graphics
{

	GraphicsSystem::GraphicsSystem(Logger* logger, std::string windowTitle, int windowSizeX, int windowSizeY, WindowMode mode, int display)
	: System(logger)
	{
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
            logger->log("Failed to initialize SDL video: " + SDL_GetError());
        else
			logger->log("Initialized SDL video successfully");

		//place window in center of screen
        SDL_DisplayMode displayMode;
        SDL_GetCurrentDisplayMode(display, displayMode);
        int windowPosX = (displayMode.w / 2) - windowSizeX;
        int windowPosY = (displayMode.h / 2) - windowSizeY;

		if (m_window = SDL_CreateWindow(windowTitle, windowPosX, windowPosY, windowSizeX, windowSizeY, SDL_WINDOW_SHOWN | mode) != 0)
            logger->log("Failed to create SDL_Window: " SDL_GetError());
		else
			logger->log("Created SDL_Window successfully");

		if (m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED) != 0) //-1 makes it choose render driver automatically
			logger->log("Failed to create SDL_Renderer: " SDL_GetError());
		else
			logger->log("Created SDL_Renderer successfully");
	}

	GraphicsSystem::~GraphicsSystem()
	{
        SDL_DestroyRenderer();
        SDL_DestroyWindow();
        SDL_VideoQuit();

        logger->log("Cleaned up Graphics System");
	}


	void GraphicsSystem::update()
	{

	}


}
