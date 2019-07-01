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

	Texture::~Texture()
	{
        SDL_DestroyTexture(m_texture);
	}


    Vector2Int Texture::getSize() const
    {
        return m_size;
    }

    int Texture::getSizeX() const
    {
        return m_size.x;
    }

    int Texture::getSizeY() const
    {
        return m_size.y;
    }

    SDL_Texture* Texture::getTexture() const
    {
        return m_texture;
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
