cmake_minimum_required(VERSION 3.10)

project(TaskManagerMVC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    main.cpp
    Task.cpp
    TaskManager.cpp
    TaskView.cpp
    TaskController.cpp
)

set(HEADERS
    Task.h
    TaskManager.h
    TaskView.h
    TaskController.h
)

add_executable(TaskManager ${SOURCES} ${HEADERS})

if (MSVC)
    target_compile_options(TaskManager PRIVATE /W4 /WX)
else()
    target_compile_options(TaskManager PRIVATE -Wall -Wextra -Werror)
endif()
