# patterned after 
# https://gitlab.kitware.com/cmake/community/-/wikis/doc/tutorials/How-to-create-a-ProjectConfig.cmake-file

cmake_minimum_required(VERSION 3.13)
cmake_policy(VERSION 3.13..3.29)
project(ZSmetalWrapper CXX)

# this stuff all winds up in the cmake-generated config file
set(ZSMETALWRAPPER_MAJOR_VERSION 0)
set(ZSMETALWRAPPER_MINOR_VERSION 1)
set(ZSMETALWRAPPER_PATCH_VERSION 0)
set(ZSMETALWRAPPER_VERSION
        ${ZSMETALWRAPPER_MAJOR_VERSION}.${ZSMETALWRAPPER_MINOR_VERSION}.${ZSMETALWRAPPER_PATCH_VERSION}        
)

# 
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
# we won't make this platform-agnostic since it's explicitly an Apple wrapper
set(INSTALL_CMAKE_DIR lib/cmake/ZSmetalWrapper CACHE PATH "Installation directory for CMake files")

# Make any relative paths absolute
foreach(p LIB INCLUDE CMAKE)
    set(var INSTALL_${p}_DIR)
    if(NOT IS_ABSOLUTE "${${var}}")
        set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
    endif()
endforeach()

#
include_directories(
        "${PROJECT_SOURCE_DIR}" # to find metal_wrapper.hpp
        "${PROJECT_BINARY_DIR}" # to find config.hpp
)

#
add_subdirectory(src)

# Add all targets to the build-tree export set
export(TARGETS ZSmetalWrapper
        FILE "${PROJECT_BINARY_DIR}/ZSmetalWrapperTargets.cmake"
)

# Export the package for use from the build-tree
export(PACKAGE ZSmetalWrapper)

# Create the CMake config files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}" "${INSTALL_INCLUDE_DIR}/ZSmetalWrapper")
message("${INSTALL_CMAKE_DIR}")
message("${INSTALL_INCLUDE_DIR}")
message("${REL_INCLUDE_DIR}")
# .. for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(ZSmetalWrapperConfig.cmake.in
        ${PROJECT_BINARY_DIR}/ZSmetalWrapperConfig.cmake @ONLY
)
# .. for the install tree
set(CONF_INCLUDE_DIRS "\${ZSMETALWRAPPER_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(ZSmetalWrapperConfig.cmake.in
        "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/ZSmetalWrapperConfig.cmake" @ONLY 
)
message("${ZSMETALWRAPPER_CMAKE_DIR}")
message("${CONF_INCLUDE_DIRS}")
# .. for both
configure_file(ZSmetalWrapperConfigVersion.cmake.in
        "${PROJECT_BINARY_DIR}/ZSmetalWrapperConfigVersion.cmake" @ONLY 
)

# Install the xxxconfigXXX.cmake files
install(FILES
        "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/ZSmetalWrapperConfig.cmake" 
        "${PROJECT_BINARY_DIR}/ZSmetalWrapperConfigVersion.cmake" 
        DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev 
)

#message(${INSTALL_CMAKE_DIR})
#message(${INSTALL_LIB_DIR})
#message(${INSTALL_INCLUDE_DIR})
#message("${ZSmetalWrapperTargets}")

# Install the export set for use with the install tree
install(EXPORT ZSmetalWrapperTargets 
        DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev
)















