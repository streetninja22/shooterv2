#include "graphics/ParticleManager.h"
#include "graphics/Particle.h"
#include "general/Logger.h"

#include <utility>

namespace graphics
{
	
	ParticleManager::ParticleManager(Uint32 particlePoolSize) : m_lastLiveIndex(-1), m_particlePoolSize(particlePoolSize)
	{
		Logger::log("Initializing a particle manager");
		m_particleArray = static_cast<Particle*>(calloc(particlePoolSize, sizeof(Particle)));
		
		//create list of dead particles. Iterates over all items except the last because the last has no next item to point to
		for (Uint32 index = 0; index < particlePoolSize - 1; ++index)
		{
			*at(index) = Particle(at(index + 1));
		}
		
		m_deadListHead = at(0);
		Logger::log("Finished initializing a particle manager successfully");
	}
	
	
	ParticleManager::~ParticleManager()
	{
		Logger::log("Freeing a particle manager");
		free(m_particleArray);
	}
	
	
	Particle* ParticleManager::at(Uint32 index)
	{
		if (index >= 0 && index < m_particlePoolSize)
			return &(m_particleArray[index]);
		return nullptr;
	}
	
	
	void ParticleManager::create(Point_t position, Vector2 velocity, Vector2 acceleration, color_t color, Vector2 size, ticks_t lifetime)
	{
		Particle* newParticle = m_deadListHead;
		m_deadListHead = m_deadListHead->nextDead();
		
		*newParticle = Particle(position, velocity, acceleration, color, size, lifetime);
	}
	
	void ParticleManager::kill(Uint32 index)
	{
		std::swap<Particle>(*at(index), *at(m_lastLiveIndex));
		
		Particle* deadParticle = at(m_lastLiveIndex);
		--m_lastLiveIndex;
		
		*deadParticle = Particle(m_deadListHead);
		m_deadListHead = deadParticle;
	}
	
};