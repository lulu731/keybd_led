add_library( cmd_option
    cmd_option.cpp
    cmd_option_map.cpp
    animation.cpp
    colors.cpp
    times.cpp
)

target_include_directories( cmd_option
    PRIVATE ../../
)