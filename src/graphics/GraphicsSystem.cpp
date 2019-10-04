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
		updateScreen();
	}


	void GraphicsSystem::updateScreen()
	{
		SDL_RenderPresent(m_renderer);
		SDL_RenderClear(m_renderer);
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


	void GraphicsSystem::renderTexture(Texture texture, Vector2Int position)
	{
		SDL_Rect dstRect = { position.x, position.y, texture.getWidth(), texture.getHeight() };
		//if statement to check for errors
		if (SDL_RenderCopy(m_renderer, texture.getTexture(), NULL, &dstRect) != 0)
		{
			Logger::logSDLError("Failed to render texture");
		}
	}
	

	void GraphicsSystem::renderTexture(Texture texture, RectInt dstRect)
	{
		//if statement to check for errors
		if (SDL_RenderCopy(m_renderer, texture.getTexture(), NULL, RectIntToSDLRect(dstRect)) != 0)
		{
			Logger::logSDLError("Failed to render texture");
		}
	}

	void GraphicsSystem::renderSprite(Sprite sprite, Vector2Int position)
	{
		SDL_Rect dstRect = { position.x, position.y, sprite.getWidth(), sprite.getHeight() };
		//if statement to check for errors
		if (SDL_RenderCopy(m_renderer, sprite.getTexture(), RectIntToSDLRect(sprite.getSourceRect()), &dstRect) != 0)
		{
			Logger::logSDLError("Failed to render sprite");
		}
	}

	void GraphicsSystem::renderSprite(Sprite sprite, RectInt dstRect)
	{
		//if statement to check for errors
		if (SDL_RenderCopy(m_renderer, sprite.getTexture(), RectIntToSDLRect(sprite.getSourceRect()), RectIntToSDLRect(dstRect)) != 0)
		{
			Logger::logSDLError("Failed to render sprite");
		}
	}

	void GraphicsSystem::clear()
	{
		SDL_RenderClear(m_renderer);
	}
}
