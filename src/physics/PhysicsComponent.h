#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include "general/constructs.h"
#include "PhysicsSystem.h"

namespace physics
{

	class PhysicsComponent
	{
		Vector2 m_position;
		Vector2 m_size;
		Vector2 m_velocity;
		Vector2 m_acceleration;

	public:
		/* Default constructor; creates a blank instance of PhysicsComponent
		*/
		PhysicsComponent();

		/* Creates an instance of PhysicsComponent with the given properties
		*
		* @param position The initial position which the object is located at
		* @param size The X/Y size of the object
		* @param velocity The initial velocity of the object
		* @param acceleration The object's acceleration
		*/
		PhysicsComponent(Vector2 position, Vector2 size, Vector2 velocity = { 0, 0 }, Vector2 acceleration = { 0, 0 });

		/* Updates the position and velocity of the object
		*
		* @param time The time passed since the last update
		*/
		void update(ticks_t time);
		
		Vector2 getPosition();
		Vector2 getSize();
		Vector2 getVelocity();
		Vector2 getAcceleration();

	};


}



#endif