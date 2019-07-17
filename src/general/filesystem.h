#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>

typedef std::string path_t;

/* Returns the full path of a file within the /data/ folder
* param file The name of the file or relative path from data folder
*/
std::string getDataFile(path_t file = "");

/* Returns the current working directory of the project. Will be the location of the executable
*/
std::string getCurrentWorkingDir();

/* Returns the full path for a file within the game directory
* param file The filepath, relative to the main game directory.
*/
std::string getFile(path_t file);

#endif
