#
# test_animations
#
add_executable ( test_animation
    test_animation.cpp
)

target_link_libraries( test_animation
    PRIVATE cmd_option
)

target_include_directories( test_animation
    PRIVATE ../ )

add_test( NAME animations COMMAND $<TARGET_FILE:test_animation> )


#
# test_colors
#
add_executable ( test_colors
    test_colors.cpp
)

target_link_libraries( test_colors
    PRIVATE cmd_option
)

target_include_directories( test_colors
    PRIVATE ../ )

add_test( NAME colors COMMAND $<TARGET_FILE:test_colors> )


#
# test_times
#
add_executable ( test_times
    test_times.cpp
)

target_link_libraries( test_times
    PRIVATE cmd_option
)

target_include_directories( test_times
    PRIVATE ../ )

add_test( NAME times COMMAND $<TARGET_FILE:test_times> )