#include "graphics/GraphicsSystem.h"

namespace graphics
{

	GraphicsSystem::GraphicsSystem(Logger* m_logger, std::string windowTitle, int windowSizeX, int windowSizeY, WindowMode mode, int display)
	: System(m_logger)
	{
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
            m_logger->log(str("Failed to initialize SDL video: ") + str(SDL_GetError()));
        else
			m_logger->log("Initialized SDL video successfully");

		//place window in center of screen
        SDL_DisplayMode* displayMode;
        SDL_GetCurrentDisplayMode(display, displayMode);
        int windowPosX = (displayMode->w / 2) - windowSizeX;
        int windowPosY = (displayMode->h / 2) - windowSizeY;

		m_window = SDL_CreateWindow(windowTitle.c_str(), windowPosX, windowPosY, windowSizeX, windowSizeY, SDL_WINDOW_SHOWN | mode);
		if (m_window == NULL)
            m_logger->log(str("Failed to create SDL_Window: ") +  str(SDL_GetError()));
		else
			m_logger->log("Created SDL_Window successfully");

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED); //-1 makes it choose render driver automatically
		if (m_renderer == NULL)
			m_logger->log(str("Failed to create SDL_Renderer: ") + str(SDL_GetError()));
		else
			m_logger->log("Created SDL_Renderer successfully");
	}

	GraphicsSystem::~GraphicsSystem()
	{
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_VideoQuit();

        m_logger->log("Cleaned up Graphics System");
	}


	void GraphicsSystem::update()
	{

	}


}
