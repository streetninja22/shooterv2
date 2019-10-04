#include "PhysicsComponent.h"

namespace physics
{

	PhysicsComponent::PhysicsComponent()
	{
		
	}


	void PhysicsComponent::update()
	{
		m_velocity += m_acceleration;
		m_position += m_velocity;
	}


	Vector2 PhysicsComponent::getPosition()
	{
		return m_position;
	}

	Vector2 PhysicsComponent::getSize()
	{
		return m_size;
	}

	Vector2 PhysicsComponent::getVelocity()
	{
		return m_velocity;
	}

	Vector2 PhysicsComponent::getAcceleration()
	{
		return m_acceleration;
	}

}