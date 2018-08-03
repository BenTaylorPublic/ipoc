cmake_minimum_required(VERSION 3.2)
project(bosssim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
        src/main.cpp
        src/Circle.h
        src/Circle.cpp
        src/Color.h
        src/Color.cpp
        src/Conversions.h
        src/Conversions.cpp
        src/Debug.h
        src/Debug.cpp
        src/DecimatedProcess.h
        src/DecimatedProcess.cpp
        src/DecimatedProcessHandler.h
        src/DecimatedProcessHandler.cpp
        src/Drawable.h
        src/Drawable.cpp
        src/FileManager.h
        src/FileManager.cpp
        src/Font.h
        src/Font.cpp
        src/Frame.h
        src/Frame.cpp
        src/Identifiable.h
        src/Identifiable.cpp
        src/InputController.h
        src/InputController.cpp
        src/InputEnums.h
        src/IpocSettings.h
        src/Line.h
        src/Line.cpp
        src/MasterController.h
        src/MasterController.cpp
        src/OnscreenButton.h
        src/OnscreenButton.cpp
        src/OutputController.h
        src/OutputController.cpp
        src/Point2D.h
        src/Point2D.cpp
        src/ProcessController.h
        src/ProcessController.cpp
        src/Rectangle.h
        src/Rectangle.cpp
        src/Settings.h
        src/Settings.cpp
        src/Sprite.h
        src/Sprite.cpp
        src/Storage.h
        src/Storage.cpp
        src/Text.h
        src/Text.cpp
        src/Texture.h
        src/Texture.cpp
        src/ThreadManager.h
        src/ThreadManager.cpp
        src/TrackedClasses.h
        src/TrackedClasses.cpp
        src/View.h
        src/View.cpp
        src/Window.h
        src/Window.cpp
        )
add_executable(bosssim ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML COMPONENTS system window graphics audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(bosssim ${SFML_LIBRARIES})
endif ()
