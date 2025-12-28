cmake_minimum_required(VERSION 3.16)
project(BasicGuiApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find wxWidgets
find_package(wxWidgets 3.2 REQUIRED COMPONENTS core base)

# Include wxWidgets headers
include(${wxWidgets_USE_FILE})

# Define the executable
add_executable(BasicGuiApp
    src/MyApp.cpp
    src/MyApp.h
    src/MainFrame.cpp
    src/MainFrame.h
)

# Link wxWidgets libraries
target_link_libraries(BasicGuiApp PRIVATE ${wxWidgets_LIBRARIES})
