#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "general/System.h"
#include "general/constructs.h"
#include "general/Logger.h"
#include "general/filesystem.h"
#include "graphics/Texture.h"

namespace graphics
{

    enum WindowMode
    {
        WINDOW_MODE_WINDOWED,
        WINDOW_MODE_FULLSCREEN,
        WINDOW_MODE_BORDERLESS,
        WINDOW_MODE_MAX
    };

	class GraphicsSystem : public System
	{

		SDL_Window* m_window;
		SDL_Renderer* m_renderer;

	public:
        GraphicsSystem(std::string windowName, int windowSizeX, int windowSizeY, WindowMode mode, int display=0);
        ~GraphicsSystem();

		void update() override;

		Texture loadTexture(path_t path);

        void renderTexture(Texture texture, Vector2Int position);

        void renderSprite(Sprite sprite, Vector2Int position);

	};

}


#endif
