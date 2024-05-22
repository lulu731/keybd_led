#
# test_animations
#
add_executable ( test_animation
    test_animation.cpp
    ../src/animation.cpp )

target_include_directories( test_animation
    PRIVATE ../ )

add_test( NAME animations COMMAND $<TARGET_FILE:test_animation> )


#
# test_colors
#
add_executable ( test_colors
    test_colors.cpp
    ../src/colors.cpp )

target_include_directories( test_colors
    PRIVATE ../ )

add_test( NAME colors COMMAND $<TARGET_FILE:test_colors> )