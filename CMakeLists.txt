cmake_minimum_required(VERSION 3.2)
project(bosssim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES mastercontroller.cpp circle.cpp color.cpp conversions.cpp debug.cpp decimatedprocess.cpp decimatedprocesshandler.cpp drawable.cpp filemanager.cpp font.cpp frame.cpp identifiable.cpp inputcontroller.cpp inputenums.h line.cpp onscreenbutton.cpp outputcontroller.cpp point2d.cpp processcontroller.cpp rectangle.cpp settings.cpp sprite.cpp storage.cpp text.cpp texture.cpp threadmanager.cpp trackedclasses.cpp view.cpp window.cpp ipocsettings.h main.cpp)
add_executable(bosssim ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML COMPONENTS system window graphics audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(bosssim ${SFML_LIBRARIES})
endif ()
