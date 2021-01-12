#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "general/System.h"
#include "general/constructs.h"
#include "general/Logger.h"
#include "general/filesystem.h"
#include "graphics/Texture.h"
#include "graphics/ParticleManager.h"

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

		/* Clears the screen then renders a new frame
		*
		*/
		void updateScreen();

		/* Loads a texture from a filepath. Returns the texture
		*
		* @param path The file path for texture to load
		*/
		Texture loadTexture(path_t path);
		
		

		/* Renders a texture to the screen at the given position
		*
		* @param texture The texture to render
		* @param position The position to render the texture at on the screen (in pixels)
		*/
        void renderTexture(Texture texture, Vector2Int position);

		/* Renders a texture within the given rectangle, resizing it to fit
		*
		* @param texture The texture to render
		* @Param dstRect The rectangle to render the texture within. The texture will take the rectangle's width and height
		*/
		void renderTexture(Texture texture, RectInt dstRect);

		/* Renders a given sprite at the position specified
		*
		* @param sprite The sprite to render
		* @param position The position to render the sprite at
		*/
        void renderSprite(Sprite sprite, Vector2Int position);

		/* Renders a given sprite within the given rectangle, resizing it to fit
		*
		* @param sprite The sprite to render
		* @param dstRect The rectangle to render the sprite within. The sprite will take the rectangle's width and height
		*/
		void renderSprite(Sprite sprite, RectInt dstRect);

		/* Clears the screen
		*
		*/
		void clear();


	};

}


#endif
