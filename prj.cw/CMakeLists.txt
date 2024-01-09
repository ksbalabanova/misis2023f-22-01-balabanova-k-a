cmake_minimum_required(VERSION 3.26)
project(kettle)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)

set(SOURCES
        main.cpp
        colorcube.cpp
)
add_executable(kettle ${SOURCES})
add_subdirectory(ext)

find_package(VTK REQUIRED)
find_package(OpenCV REQUIRED)

include(${VTK_USE_FILE})
set(VTK_DIR/Users/balabashka/CLionProjects)

target_include_directories(kettle PRIVATE ${VTK_INCLUDE_DIRS})
target_link_libraries(
        kettle
        ${VTK_LIBRARIES}
        ${OpenCV_LIBS}
        imgui_impl_glfw
        imgui_impl_opengl3
        ImGuiFileDialog
)
