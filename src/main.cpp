#include <iostream>
#include "general/Logger.h"
#include "general/filesystem.h"

int main()
{
    Logger logger = Logger(getCurrentWorkingDir());

    logger.log("Hello, World!");

    return 0;
}
