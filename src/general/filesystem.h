#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>

/* Returns the full path of a file within the /data/ folder
* param file The name of the file or relative path from data folder
*/
std::string getDataFile(std::string file = "");

/* Returns the current working directory of the project. Will be the location of the executable
*/
std::string getCurrentWorkingDir();

/* Returns the full path for a file within the game directory
* param file The filepath, relative to the main game directory.
*/
std::string getFile(std::string file);

#endif
