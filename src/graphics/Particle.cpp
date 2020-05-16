#include "Particle.h"

namespace graphics
{
	
	void Particle::update(time_t timeElapsed)
	{
		if (!isDead()) //make sure not to access invalid fields
		{
			m_velocity += m_acceleration * timeElapsed * G_MS_TO_S_MULTIPLIER;
			m_position += m_acceleration * timeElapsed * G_MS_TO_S_MULTIPLIER;
			
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
	
};