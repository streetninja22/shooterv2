#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include "general/System.h"

namespace physics
{

	class PhysicsSystem : public System
	{

	public:
		PhysicsSystem();

		void update();

	};


}


#endif