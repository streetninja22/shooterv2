#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include "general/constructs.h"

namespace graphics
{

	class Texture
	{
		SDL_Texture* m_texture;

		Vector2Int m_size;

	public:
		Texture();
		Texture(SDL_Texture* texture);
        ~Texture();

		Vector2Int getSize() const;
		int getWidth() const;
		int getHeight() const;

		SDL_Texture* getTexture() const;

		void clearTexture();
	};



    class Sprite : public Texture
    {
        RectInt m_sourceRect;

	public:
        Sprite();
        Sprite(SDL_Texture* texture, RectInt sourceRect);
        Sprite(Texture texture, RectInt sourceRect);

        RectInt getSourceRect();
    };

}



#endif
