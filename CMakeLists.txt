cmake_minimum_required(VERSION 3.20)
project(legacy_glut_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Force macOS to build for Intel Architecture
set(CMAKE_OSX_ARCHITECTURES "x86_64")

# Find the native macOS OpenGL and GLUT packages
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

# Include the directories for GLUT and OpenGL headers
include_directories(${GLUT_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} gl/ src/)

# Define your executable and its source files
add_executable(app 
    src/main.cpp 
    src/visuals.cpp  # Make sure this file exists in your src/ folder!
)

# Link your app against GLUT and OpenGL frameworks
target_link_libraries(app 
    PRIVATE 
        ${GLUT_LIBRARIES} 
        ${OPENGL_LIBRARIES}
)