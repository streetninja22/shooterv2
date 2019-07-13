
#include <iostream>
#include "general/Logger.h"
#include "general/filesystem.h"
#include "graphics/GraphicsSystem.h"


int main()
{
	Logger* logger = new Logger(getCurrentWorkingDir());

    logger->log("Starting");
    graphics::GraphicsSystem* graphics = new graphics::GraphicsSystem(logger, "Test", 512, 512, graphics::WINDOW_MODE_WINDOWED);

    return 0;
}
