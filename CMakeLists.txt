
cmake_minimum_required(VERSION 3.15)
project(SpartanSuitNative LANGUAGES CXX)

# Set C++ standard and compilation database
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  # Required for compile_commands.json

# MSVC-specific settings
if(MSVC)
    add_compile_options(/W4 /WX /permissive-)
    # Some win32 definitions we need for the socket code to link properly
    add_definitions(-D_WINSOCK_DEPRECATED_NO_WARNINGS -DNOMINMAX -DWIN32_LEAN_AND_MEAN)
    # Disable Windows.h min/max macros
    add_definitions(-DNOMINMAX)
endif()

# Explicit source file listing (better than GLOB for real projects)
set(SOURCES
    main.cpp
    Math/Vector3.cpp
    RemoteConnection/Joint.cpp
    RemoteConnection/Server/NetworkDefinitions.cpp
    RemoteConnection/Server/UDPServer.cpp
)

# Create executable
add_executable(SpartanSuitNative ${SOURCES})
target_link_libraries(SpartanSuitNative PRIVATE ws2_32)

# Include directories
target_include_directories(SpartanSuitNative PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils
    ${CMAKE_CURRENT_SOURCE_DIR}/Math
    ${CMAKE_CURRENT_SOURCE_DIR}/RemoteConnection
    ${CMAKE_CURRENT_SOURCE_DIR}/RemoteConnection/Server
)

# Ensure compile_commands.json is available
add_custom_command(TARGET SpartanSuitNative POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
    COMMENT "Copying compile_commands.json to source directory"
)
