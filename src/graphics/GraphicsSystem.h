#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

#include <SDL.h>
#include "general/System.h"
#include "general/constructs.h"

namespace graphics
{

	class GraphicsSystem : public System
	{

	public:
        GraphicsSystem();
        ~GraphicsSystem();

		void update() override;

	};

}


#endif
