#
# test_animations
#
add_executable ( test_animations
    test_animations.cpp
    ../src/animations.cpp )

target_include_directories( test_animations
    PRIVATE ../ )


add_test( NAME animations COMMAND $<TARGET_FILE:test_animations> )