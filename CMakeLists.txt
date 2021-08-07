cmake_minimum_required(VERSION 3.0)

project(ShooterGame)

set(PROGRAM_NAME "ShooterGame")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR}/src/)

set(HEADERS " ")
set(SOURCES " ")

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

add_subdirectory("${SOURCE_DIR}")

add_executable(${PROGRAM_NAME}; ${SOURCES}; ${HEADERS})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL_INCLUDE_DIR})
include_directories(${SD2_IMAGE_INCLUDE_DIR})
include_directories(${SDL2_MIXER_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})

link_directories(${SDL2_LIBRARY_DIR})
link_directories(${SDL2_IMAGE_LIBRARY_DIR})
link_directories(${SDL_MIXER_LIBRARY_DIR})
link_directories(${SDL_TTF_LIBRARY_DIR})


target_link_libraries(${PROGRAM_NAME} ${SDL2_LIBRARY}; ${SDL2_IMAGE_LIBRARY}; ${SDL2_TTF_LIBRARY}; ${SDL2_MIXER_LIBRARY})


#Fix issue of standard library not being linked when using MinGW on Windows
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND WIN32)
	add_compile_options(--target=x86_64-w64-windows-gnu)
endif()

target_compile_definitions(${PROGRAM_NAME} PRIVATE DEBUG_MAIN_DIR="C:/Documents/Projects/Game/")
