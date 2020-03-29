#include "PhysicsComponent.h"

namespace physics
{

	PhysicsComponent::PhysicsComponent()
	{
		
	}

	PhysicsComponent::PhysicsComponent(Vector2 position, Vector2 size, Vector2 velocity, Vector2 acceleration) : m_position(position), m_size(size), m_velocity(velocity) , m_acceleration(acceleration)
	{

	}


	void PhysicsComponent::update(Uint32 time)
	{
		m_velocity += m_acceleration * time * G_TIME_SCALE_MULTIPLIER;
		m_position += m_velocity * time * G_TIME_SCALE_MULTIPLIER;
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