cmake_minimum_required(VERSION 3.16)

project(chapter_1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

set(SOURCES
    main.cpp
    Recipe.h
    Recipe.cpp
    Chef.h
    Chef.cpp)

qt_add_executable(appchapter_1 ${SOURCES})

set_target_properties(appchapter_1 PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appchapter_1
    PRIVATE Qt6::Core
)

include(GNUInstallDirs)
install(TARGETS appchapter_1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
