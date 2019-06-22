#include "filesystem.h"

#define DEBUG_MODE //use this when debugging. remove on release build
//make sure to set your main directory path in the cmake file's add_definitions

//get working directory functions depending on operating system
#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd

#else
#include <unistd.h>

#endif

#ifdef DEBUG_MODE //debug current working directory

#define STRINGIZE(x) #x

std::string getCurrentWorkingDir()
{
	return std::string(DEBUG_MAIN_DIR);
}


#else //release current working directory

/* Returns the current working directory of the project. Will be the location of the executable
*/
std::string getCurrentWorkingDir()
{
    char buffer[FILENAME_MAX];
    getcwd(buffer, FILENAME_MAX);
    std::string current_working_dir(buffer);
    return current_working_dir;
}
#endif // DEBUG_MODE

std::string getDataFile(std::string file)
{
	return getCurrentWorkingDir() + "data/" + file;
}

std::string getFile(std::string file)
{
    return getCurrentWorkingDir() + file;
}
