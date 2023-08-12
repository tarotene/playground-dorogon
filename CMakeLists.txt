cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
  drogon_init
  VERSION 0.1.0
  DESCRIPTION "Simple playground on drogon"
  HOMEPAGE_URL "https://example.com/"
  LANGUAGES CXX)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Submodule guard ----

# NOTE: This removes any concern about submodules.
# See also: https://cliutils.gitlab.io/modern-cmake/chapters/projects/submodule.html

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/drogon/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# ---- Declare external libraries ----

add_subdirectory(external/drogon)

# ---- Declare executable ----

add_executable(drogon_init_exe src/main.cpp)
add_executable(drogon_init::exe ALIAS drogon_init_exe)

set_property(TARGET drogon_init_exe PROPERTY OUTPUT_NAME drogon_init)

target_compile_features(drogon_init_exe PRIVATE cxx_std_17)

target_link_libraries(drogon_init_exe PRIVATE drogon)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT drogon_init_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
    AUTHOR_WARNING "Developer mode is intended for developers of drogon_init")
endif()

include(cmake/dev-mode.cmake)
