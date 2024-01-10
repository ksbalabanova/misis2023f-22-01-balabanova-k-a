cmake_minimum_required(VERSION 3.26)
project(kettle)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)

add_executable(kettle main.cpp)
add_subdirectory(ext)

find_package(OpenCV REQUIRED)

target_link_libraries(
        kettle
        ${OpenCV_LIBS}
        imgui_impl_glfw
        imgui_impl_opengl3
        ImGuiFileDialog
)
