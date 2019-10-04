#include "graphics/Texture.h"

namespace graphics
{

	Texture::Texture() : m_texture(nullptr)
	{
		m_size.x = 0;
		m_size.y = 0;
	}

	Texture::Texture(SDL_Texture* texture) : m_texture(texture)
	{
        SDL_QueryTexture(m_texture, nullptr, nullptr, &(m_size.x), &(m_size.y));
	}


    Vector2Int Texture::getSize() const
    {
        return m_size;
    }

    int Texture::getWidth() const
    {
        return m_size.x;
    }

    int Texture::getHeight() const
    {
        return m_size.y;
    }

    SDL_Texture* Texture::getTexture() const
    {
        return m_texture;
    }

	void Texture::clearTexture()
	{
		SDL_DestroyTexture(m_texture);
	}


    Sprite::Sprite() : Texture()
    {

    }

    Sprite::Sprite(SDL_Texture* texture, RectInt sourceRect) : Texture(texture), m_sourceRect(sourceRect)
    {

    }

    Sprite::Sprite(Texture texture, RectInt sourceRect) : Texture(texture), m_sourceRect(sourceRect)
    {

    }



    RectInt Sprite::getSourceRect()
    {
		return m_sourceRect;
    }

}
