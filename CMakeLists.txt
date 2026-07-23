set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

cmake_minimum_required(VERSION 3.25)
project(SpaceTracking VERSION 0.0.1 LANGUAGES CXX)
include(FetchContent)

FetchContent_Declare(
    MapKitCpp
    GIT_REPOSITORY https://github.com/DiCode77/MapKitCpp.git
    GIT_TAG main
)

FetchContent_MakeAvailable(MapKitCpp)

set(SRC_FILES "${CMAKE_SOURCE_DIR}/src")
set(SRC_FILES_UTILITES "${SRC_FILES}/utilites")
set(SRC_FILES_GUI "${SRC_FILES}/gui")
set(SRC_FILES_GUI_WINDOW "${SRC_FILES_GUI}/window")
set(SRC_FILES_GUI_PANELS "${SRC_FILES_GUI}/panels")
set(APP_ICON resource/SpTracking.icns)
set(APP_MIN_MACOS_VERS "26.0")
set(CMAKE_OSX_DEPLOYMENT_TARGET ${APP_MIN_MACOS_VERS})

find_package(wxWidgets CONFIG REQUIRED)

file(GLOB_RECURSE LIST_FILES_UTILITES "${SRC_FILES_UTILITES}/*.hpp" "${SRC_FILES_UTILITES}/*.cpp") 
file(GLOB_RECURSE LIST_FILES_GUI_WINDOWS "${SRC_FILES_GUI_WINDOW}/*.hpp" "${SRC_FILES_GUI_WINDOW}/*.cpp")
file(GLOB_RECURSE LIST_FILES_GUI_PANELS "${SRC_FILES_GUI_PANELS}/*.hpp" "${SRC_FILES_GUI_PANELS}/*.cpp")
file(GLOB_RECURSE APP_RESOURCES  "${CMAKE_SOURCE_DIR}/resources/*.icns")

add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${LIST_FILES_UTILITES} ${LIST_FILES_GUI_WINDOWS} ${LIST_FILES_GUI_PANELS})

source_group("src\\utilites" FILES ${LIST_FILES_UTILITES})
source_group("src\\gui\\window" FILES ${LIST_FILES_GUI_WINDOWS})
source_group("src\\gui\\panels" FILES ${LIST_FILES_GUI_PANELS})

set_target_properties(${PROJECT_NAME} PROPERTIES 
                                                 CXX_STANDARD 23 
                                                 CXX_STANDARD_REQUIRED ON
                                                 MACOSX_BUNDLE TRUE
                                                 MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/Info.plist
                                                 MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
                                                 MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION})
                                

set_source_files_properties(${APP_RESOURCES} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_FILES})

target_link_libraries(${PROJECT_NAME}  PRIVATE wx::core wx::base MapKitCpp)

target_sources(${PROJECT_NAME} PRIVATE ${APP_RESOURCES})