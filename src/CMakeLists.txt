cmake_minimum_required(VERSION 3.13)
cmake_policy(VERSION 3.13..3.29)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(CMAKE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/cmake)
file(GLOB MACROS ${CMAKE_INCLUDE_DIR}/*.macros)
foreach(MC ${MACROS})
        message(STATUS "Including macro ${MC}")
        include(${MC})
endforeach()

configure_file(config.hpp.in "${CMAKE_CURRENT_BINARY_DIR}/config.hpp" @ONLY)

add_library(ZSmetalWrapper 
        _ZS_smart_pointer.hpp
        ZS_metal_device.cpp
        ZS_metal_device.hpp 
        device_smart_pointer.hpp
        metal_wrapper.hpp
)

set_target_properties(ZSmetalWrapper PROPERTIES
        PUBLIC_HEADER 
        "metal_wrapper.hpp;_ZS_smart_pointer.hpp;ZS_metal_device.hpp;device_smart_pointer.hpp;${CMAKE_CURRENT_BINARY_DIR}/config.hpp"
)

target_include_directories(ZSmetalWrapper PRIVATE
        "/usr/local/include/metal-cpp"
        ${PROJECT_SOURCE_DIR}/src
)

add_osx_framework(Metal ZSmetalWrapper)
add_osx_framework(Foundation ZSmetalWrapper)

target_compile_features(ZSmetalWrapper PUBLIC cxx_std_17)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

install(TARGETS ZSmetalWrapper
        EXPORT ZSmetalWrapperTargets
        LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
        PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/ZSmetalWrapper" COMPONENT dev
)


