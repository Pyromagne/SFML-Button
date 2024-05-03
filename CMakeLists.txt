cmake_minimum_required(VERSION 3.26)

project(SFMLButton)

set(SFML_INCLUDE_DIR "" CACHE PATH "Path to SFML include directory")
set(SFML_LIB_DIR "" CACHE PATH "Path to SFML lib directory")

include_directories(
    ${SFML_INCLUDE_DIR}
)

add_library(SFMLButton STATIC
    src/Button.cpp
    src/EllipseButton.cpp
    src/RectButton.cpp
)

target_link_directories(SFMLButton PUBLIC
    ${SFML_LIB_DIR}
    lib
)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    target_link_libraries(SFMLButton PUBLIC
        sfml-audio-d
        sfml-graphics-d
        sfml-main-d
        sfml-network-d
        sfml-system-d
        sfml-window-d
    )
else()
    target_link_libraries(SFMLButton PUBLIC
        sfml-audio
        sfml-graphics
        sfml-main
        sfml-network
        sfml-system
        sfml-window
        ColorEscape
    )
endif()

install(TARGETS SFMLButton
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)