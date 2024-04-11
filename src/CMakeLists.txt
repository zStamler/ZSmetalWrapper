cmake_minimum_required(VERSION 3.13)
cmake_policy(VERSION 3.13..3.29)

include(addOSXframework.macro)

configure_file(config.hpp.in "${CMAKE_CURRENT_BINARY_DIR}/config.hpp" @ONLY)

add_library(ZSmetalWrapper 
        dummy.cpp # there has to be at least one source file or CMake freaks out
        _ZS_smart_pointer.hpp
        ZS_metal_device_smart_pointer.hpp
        ZS_metal_command_queue_smart_pointer.hpp
        metal_wrapper.hpp
)

set_target_properties(ZSmetalWrapper PROPERTIES
        PUBLIC_HEADER 
        "metal_wrapper.hpp;_ZS_smart_pointer.hpp;ZS_metal_device_smart_pointer.hpp;ZS_metal_command_queue_smart_pointer.hpp;${CMAKE_CURRENT_BINARY_DIR}/config.hpp"
)

target_include_directories(ZSmetalWrapper PRIVATE
        "/usr/local/include/metal-cpp"
        ${PROJECT_SOURCE_DIR}/src
)

ADD_OSX_FRAMEWORK(Metal ZSmetalWrapper)
ADD_OSX_FRAMEWORK(Foundation ZSmetalWrapper)

target_compile_features(ZSmetalWrapper PUBLIC cxx_std_17)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

install(TARGETS ZSmetalWrapper
        EXPORT ZSmetalWrapperTargets
        LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
        PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/ZSmetalWrapper" COMPONENT dev
)


