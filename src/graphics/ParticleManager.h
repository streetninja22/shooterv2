#ifndef PARTICLE_MANAGER
#define PARTICLE_MANAGER

#include "graphics/Particle.h"

namespace graphics
{
	class ParticleManager
	{
		//the size of the particle pool measured in the number of Particle objects
		Uint32 m_particlePoolSize;
		
		//the first item of the particle array memory block
		Particle* m_particleArray;
		
		//the head of the list of dead particles
		Particle* m_deadListHead;
		
		//the index of the live particle furthest from the beginning of the array
		Uint32 m_lastLiveIndex;
		
	public:
	ParticleManager(Uint32 particlePoolSize);
	
	~ParticleManager();
	
	/* Returns the particle at the given array index. Returns nullptr if the index does not exist
	 * 
	 * @param index The index of the item to return
	 */
	Particle* at(Uint32 index);
	
	/* Spawns a new particle at the head of the dead particle list
	 * 
	 * @param position The position of the particle on the sceen
	 * @param velocity The velocity vector of the particle
	 * @param acceleration The acceleration vector of the paticle
	 * @param color The color of a "colored pixel" particle
	 * @param size The size of a "colored pixel" particle
	 * @param lifetime The lifetime of the particle in frames 
	 */
	void create(Vector2 position, Vector2 velocity, Vector2 acceleration, color_t color, Vector2 size, ticks_t lifetime);
	
	/* Destroys the particle at the given index and makes it the new head of the dead particle list
	 * 
	 * @param index The index of the particle within the array
	 */ 
	void kill(Uint32 index);
	
	/* Renders the given particle onto the screen
	 * 
	 * @param particle The particle to render
	 */ 
	void renderParticle(Particle* particle);
	
	};
	
	
};


#endif