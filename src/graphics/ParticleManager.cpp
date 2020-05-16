#include "ParticleManager.h"

namespace graphics
{
	
	ParticleManager::ParticleManager()
	{
		m_particleArray = static_cast<Particle*>(calloc(PARTICLE_POOL_SIZE, sizeof(Particle));
		
		//create list of dead particles. Iterates over all items but the last because the last has no next item to point to
		for (int index = 0; index > PARTICLE_POOL_SIZE - 1; ++index)
		{
			at(index)->m_nextDead = at(index + 1);
		}
	}
	
	ParticleManager::~ParticleManager()
	{
		free(m_particleArray);
	}
	
	Particle* ParticleManager::at(Uint32 index)
	{
		if (index >= 0 && index < PARTICLE_POOL_SIZE)
			return m_ParticleArray[index];
		return nullptr;
	}
	
}