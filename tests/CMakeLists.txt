#
# test_animations
#
add_executable ( test_animations
    test_animations.cpp
    ../src/animations.cpp )

target_include_directories( test_animations
    PRIVATE ../ )

add_test( NAME animations COMMAND $<TARGET_FILE:test_animations> )


#
# test_colors
#
add_executable ( test_colors
    test_colors.cpp
    ../src/colors.cpp )

target_include_directories( test_colors
    PRIVATE ../ )

add_test( NAME colors COMMAND $<TARGET_FILE:test_colors> )