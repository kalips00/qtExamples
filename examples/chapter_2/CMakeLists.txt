cmake_minimum_required(VERSION 3.16)

project(chapter_2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

set(SOURCES
    src/main.cpp
    src/entity/Recipe.h
    src/entity/Recipe.cpp
    src/entity/RecipeListModel.h
    src/entity/RecipeListModel.cpp
    src/infrastructure/RecipeManager.h
    src/infrastructure/RecipeManager.cpp
)

qt_add_executable(appchapter_2 ${SOURCES})

qt_add_qml_module(appchapter_2
    URI chapter_2
    VERSION 1.0
    QML_FILES
    src/qml/Main.qml
)

set_target_properties(appchapter_2 PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_include_directories(appchapter_2 PUBLIC
    src/
    src/entity
    src/infrastructure
)

target_link_libraries(appchapter_2
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appchapter_2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
