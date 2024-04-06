cmake_minimum_required(VERSION 3.10) # required
project(arr)  # project name
		
file(GLOB_RECURSE headers src/headers/*.hpp)
file(GLOB_RECURSE sources src/sources/*.cpp src/sources/*.tem)
file(GLOB_RECURSE tlbx src/tlbx/*.hpp src/tlbx/*.cpp)

set(srcs src/${PROJECT_NAME}.hpp ${headers} ${sources} ${tlbx})
add_library(${PROJECT_NAME} STATIC ${srcs})

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-D${PROJECT_NAME}_STATIC_DEFINE")

target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall -Wextra -Wpedantic>
        )
        
# Enable include with <> pair
target_include_directories(${PROJECT_NAME} PUBLIC src src/headers src/tlbx)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

## build type ##
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
            "MinSizeRel" "RelWithDebInfo")
endif ()

find_package(Git QUIET)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include(compiler-flags)

option(${PROJECT_NAME}_BUILD_TESTING "Build ${PROJECT_NAME} testing targets" ON)
option(${PROJECT_NAME}_BUILD_EXAMPLES "Build ${PROJECT_NAME} example executables" ON)
option(${PROJECT_NAME}_COVERAGE "Add ${PROJECT_NAME} coverage reports" OFF)

## testing ##
if (${PROJECT_NAME}_BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif ()

## examples ##
if (${PROJECT_NAME}_BUILD_EXAMPLES)
	add_subdirectory(examples)
endif ()

add_subdirectory(vendor)

