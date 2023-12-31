cmake_minimum_required(VERSION 3.21)
project("prelog" VERSION 1.0 LANGUAGES CXX)

## QoL definitions
add_compile_definitions(-DPROJECT_VERSION="${PROJECT_VERSION}" -DBUILD_SHARED_LIBS=$<BOOL:${BUILD_SHARED_LIBS}>)

## Project's base, containing all that's to be inherited
set(PROJECT_BASE ${PROJECT_NAME}-base)
add_library(${PROJECT_BASE} INTERFACE)
target_compile_features(${PROJECT_BASE} INTERFACE cxx_std_17)
target_include_directories(${PROJECT_BASE} INTERFACE "include")

## Project's dependencies adding and linking
# if(NOT TARGET dependencytarget)
#	add_subdirectory("lib/dependency")
# endif()

# target_link_libraries(${PROJECT_BASE} INTERFACE dependencytarget)

## Source globbing, exclude main file
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp" "src/*.cxx" "src/*.cc")
list(FILTER PROJECT_SOURCES EXCLUDE REGEX "src/main.cc$")
target_sources(${PROJECT_BASE} INTERFACE ${PROJECT_SOURCES})

## Project output, end-product
set(PROJECT_TARGET ${PROJECT_NAME})
add_library(${PROJECT_TARGET} STATIC "src/main.cc")
# add_executable(${PROJECT_TARGET} "src/main.cc")
target_link_libraries(${PROJECT_TARGET} PUBLIC ${PROJECT_BASE})
