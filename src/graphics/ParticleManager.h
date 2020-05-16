#ifndef PARTICLE_MANAGER
#define PARTICLE_MANAGER

#include "graphics/Particle.h"

namespace graphics
{
	class ParticleManager
	{
		static const Uint32 PARTICLE_POOL_SIZE;
		
		//the head of the particle memory block
		Particle* m_particleArray;
		
		//the head of the list of dead particles
		Particle* m_deadListHead;
		
		//the index of the live particle furthest from the beginning of the array
		Uint32 m_liveIndex;
		
	public:
	ParticleManager();
	~ParticleManager();
	
	/* Returns the particle at the given array index. Returns nullptr if the index does not exist
	 * 
	 * @param index The index of the item to return
	 */
	Particle* at(Uint32 index);
		
		
	};
	
	
};


#endif