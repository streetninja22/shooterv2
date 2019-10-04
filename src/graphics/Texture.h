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
		/* Creates a blank texture
		*/
		Texture();

		/* Creates a Texture object from the given SDL_Texture
		*
		*/
		Texture(SDL_Texture* texture);

		/* Returns the size of the texture as a vector
		*/
		Vector2Int getSize() const;

		/* Returns the width of the texture in pixels
		*/
		int getWidth() const;

		/* Returns the height of the texture in pixels
		*/
		int getHeight() const;

		/* Returns the associated SDL_Texture
		*/
		SDL_Texture* getTexture() const;

		/* Deletes the associated SDL_Texture
		*/
		void clearTexture();
	};



    class Sprite : public Texture
    {
        RectInt m_sourceRect;

	public:
		/* Creates a blank Sprite
		*/
        Sprite();

		/* Creates a sprite from a given SDL_Texture and selection area of said texture
		*
		* @param texture The texture which the sprite is located on
		* @param sourceRect The area of the texture which the sprite is located in
		*/
        Sprite(SDL_Texture* texture, RectInt sourceRect);

		/* Creates a sprite from a given existing Texture and a selection area of said texture
		*
		* @param texture The texture which the sprite is located on
		* @param sourceRect The area of the texture which the sprite is located in
		*/
        Sprite(Texture texture, RectInt sourceRect);

		/* Gets the RectInt representing the selection area of the sprite
		*/
        RectInt getSourceRect();
    };

}



#endif
