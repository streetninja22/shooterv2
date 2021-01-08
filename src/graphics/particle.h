#ifndef PARTICLE_H
#define PARTICLE_H

#include "general/constructs.h"
#include "graphics/graphicsgeneral.h"
#include "general/Logger.h"

namespace graphics
{

	class Particle
	{
		//the number of frames before the particle despawns
		ticks_t m_framesLeft;
		
		//union makes particle store its physical data when alive and a pointer to the next in the list of dead particles when dead.
		union
		{
			struct
			{
				//kinematic properties measured in pixels and seconds
				Point_t m_position;
				Vector2 m_velocity;
				Vector2 m_acceleration;
				
				//TODO create union between particles that display as solid color rectangles and actual textures
				color_t m_color; 
			
				Vector2 m_size;
				
			} m_live;
			
			Particle* m_nextDead;
			
		};
		
	public:
	
		/* Initializes empty particle
		 */
		Particle();
		
		/* Initializes a live particle with the given properties
		 *
		 * @param position The position of the particle on the screen
		 * @param velocity The velocity vector of the particle
		 * @param acceleration The acceleration vector of the particle
		 * @param color The RGBA color value of the particle when rendered as a solid color
		 * @param size The rectangular size of the particle when rednered as a solid color
		 * @param lifetime The number of frames before the particle dies
		 */ 
		Particle(Vector2 position, Vector2 velocity, Vector2 acceleration, color_t color, Vector2 size, ticks_t lifetime);
		
		/* Initializes a dead particle with the next item in the particle list as a pointer
		 * 
		 * @param nextDead Pointer to the next item in the list of dead particles
		 */ 
		Particle(Particle* nextDead);
		
		/* Updates the state of the particle, including position as well as lifetime
		 * 
		 * @param timeElapsed the time elapsed since the last upate in frames
		 */
		void update(ticks_t timeElapsed);
		
		/* Returns true if the particle has a remaining lifetime of 0, otherwise returns false.
		 */ 
		bool isDead();
		
		/* Returns the next dead particle in the list if this particle is dead. If it is not dead, returns nullptr.
		 */ 
		Particle* nextDead();
		
		/* Sets the dead particle in the list which is pointed to
		 * 
		 * @param nextDead The new next dead particle
		 */ 
		void setNextDead(Particle* nextDead);
		
		
	};


};

#endif