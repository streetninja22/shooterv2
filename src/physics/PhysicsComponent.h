#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include "general/constructs.h"

namespace physics
{

	class PhysicsComponent
	{
		Vector2 m_position;
		Vector2 m_size;
		Vector2 m_velocity;
		Vector2 m_acceleration;

	public:
		PhysicsComponent();

		/* Updates the position and velocity of the object
		*/
		void update();
		
		Vector2 getPosition();
		Vector2 getSize();
		Vector2 getVelocity();
		Vector2 getAcceleration();

	};


}



#endif