#include "graphics/GraphicsSystem.h"

namespace graphics
{

	GraphicsSystem::GraphicsSystem(std::string windowTitle, int windowSizeX, int windowSizeY, WindowMode mode, int display)
	{
		Logger::log("Initializing Graphics System");
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
            Logger::log(str("Failed to initialize SDL video: ") + str(SDL_GetError()));
        else
			Logger::log("Initialized SDL video successfully");
		IMG_Init(IMG_INIT_PNG);

		//place window in center of screen
		SDL_DisplayMode displayMode;
        SDL_GetCurrentDisplayMode(display, &displayMode);
        int windowPosX = (displayMode.w / 2) - windowSizeX;
        int windowPosY = (displayMode.h / 2) - windowSizeY;

		m_window = SDL_CreateWindow(windowTitle.c_str(), windowPosX, windowPosY, windowSizeX, windowSizeY, SDL_WINDOW_SHOWN | mode);
		if (m_window == NULL)
            Logger::log(str("Failed to create SDL_Window: ") + str(SDL_GetError()));
		else
			Logger::log("Created SDL_Window successfully");

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED); //-1 makes it choose render driver automatically
		if (m_renderer == NULL)
			Logger::log(str("Failed to create SDL_Renderer: ") + str(SDL_GetError()));
		else
			Logger::log("Created SDL_Renderer successfully");

	}

	GraphicsSystem::~GraphicsSystem()
	{
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_VideoQuit();

        Logger::log("Cleaned up Graphics System");
	}


	void GraphicsSystem::update()
	{

	}

    Texture GraphicsSystem::loadTexture(path_t path)
    {
        SDL_Surface* surface = IMG_Load(path.c_str());
        if (surface == NULL)
		{
			Logger::logSDLError("Failed to load texture");
		}

		SDL_Texture* textureTemp = SDL_CreateTextureFromSurface(m_renderer, surface);
		if (textureTemp == NULL)
		{
			Logger::logSDLError("Failed to load texture");
		}

		return Texture(textureTemp);
    }

	void renderTexture(Texture texture, Vector2Int position)
	{

	}

	void renderSprite(Sprite sprite, Vector2Int position)
	{

	}

}
