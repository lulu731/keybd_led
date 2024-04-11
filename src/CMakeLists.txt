add_executable( kbdled
    main.cpp )

target_include_directories( kbdled
    PRIVATE ../ )

target_link_libraries( kbdled
    PRIVATE ${HIDAPI} )