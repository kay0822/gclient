cmake_minimum_required (VERSION 2.8)

project(gclient C)

set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_INSTALL_PREFIX /opt/gclient)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

# ----- I N C L U D E -----
include(CheckCmakeCompat)  		# important

include(CheckIncludeFiles)   	# Global
include(CheckLibraryExists)		# Global
include(CheckStructHasMember)	# Global

include(FindPkgConfig)
include(FeatureSummary)
include(FindFeature)
include(Find)
include(ConfigOptions)

# ----- P A C K A G E -----
set(GTK2_FEATURE_TYPE "REQUIRED") 
set(GTK2_FEATURE_PURPOSE "gtk support") 
set(GTK2_FEATURE_DESCRIPTION "gtk2 library")
find(GTK2)

# ----- C O N F I G U R E -----
add_definitions("-DHAVE_CONFIG_H")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config.h)

# ----- H E A D E R -----
include_directories(${CMAKE_CURRENT_SOURCE_DIR}) 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(include)

add_subdirectory(core)
add_subdirectory(utils)
add_subdirectory(widgets)
add_subdirectory(client)


