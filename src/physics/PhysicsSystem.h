#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include "general/System.h"

namespace physics
{
	//Multiplier used on time-dependant operations to convert milliseconds to seconds
	const double TIME_SCALE_MULTIPLIER = 0.001;


	class PhysicsSystem : public System
	{

	public:
		PhysicsSystem();

		void update();

	};


}


#endif