#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#define DEBUG_MODE //use this when debugging. remove on release build
//make sure to set a preprocessor defintion for DEBUG_MAIN_DIR as the root project folder when debugging

//get working directory functions depending on operating system
#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd

#else
#include <unistd.h>

#endif

#include <string>

#ifdef DEBUG_MODE //debug current working directory

#define STRINGIZE(x) #x

std::string getCurrentWorkingDir()
{
	return std::string(STRINGIZE(DEBUG_MAIN_DIR));
}


#else //release current working directory


std::string getCurrentWorkingDir()
{
    char buffer[FILENAME_MAX];
    getcwd(buffer, FILENAME_MAX);
    std::string current_working_dir(buffer);
    return current_working_dir;
}

#endif // DEBUG_MODE

std::string getDataFile(std::string file = "")
{
	return getCurrentWorkingDir() + "data/" + file;
}

#endif
