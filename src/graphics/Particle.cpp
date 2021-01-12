#include "graphics/Particle.h"

namespace graphics
{
	
	Particle::Particle()
	{
	}
	
	Particle::Particle(Vector2 position, Vector2 velocity, Vector2 acceleration, color_t color, Vector2 size, ticks_t lifetime, Sprite sprite, color_t rectColor, Vector2 rectSize, Vector2 spriteScale)
	: m_framesLeft(lifetime). m_sprite(sprite), m_rectColor(rectColor), m_rectSize(rectSize), m_spriteScale(spriteScale)
	{
		m_live.m_position = position;
		m_live.m_velocity = velocity;
		m_live.m_acceleration = acceleration;
		m_live.m_color = color;
		m_live.m_size = size;
	}
	
	Particle::Particle(Particle* nextDead) : m_nextDead(nextDead), m_framesLeft(0)
	{
	}
	
	
	void Particle::update(ticks_t timeElapsed)
	{
		if (!isDead()) //make sure not to access invalid fields
		{
			m_live.m_velocity += m_live.m_acceleration * timeElapsed * G_MS_TO_S_MULTIPLIER;
			m_live.m_position += m_live.m_acceleration * timeElapsed * G_MS_TO_S_MULTIPLIER;
			
			--m_framesLeft;
		}
	}
	
	bool Particle::isDead()
	{
		return !m_framesLeft;
	}
	
	Particle* Particle::nextDead()
	{
		if (isDead())
			return m_nextDead;
		return nullptr;
	}
	
	void Particle::setNextDead(Particle* nextDead)
	{
		if (isDead())
			m_nextDead = nextDead;
	}
	

	color_t Particle::getRectColor()
	{
		return m_rectColor;
	}
		
	Vector2 getRectSize()
	{
		return m_rectSize;
	}
		
	Sprite getSprite()
	{
		return m_sprite;
	}
		
	Vector2 getSpriteScale()
	{
		return m_spriteScale;
	}
		
	
};