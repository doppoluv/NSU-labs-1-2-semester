list(APPEND CPPCHECK_ARGS
    --enable=warning,style,performance,portability,unusedFunction
    --std=c99
    --verbose
    --error-exitcode=1
    --language=c
    -DMAIN=main
    -I ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/*.h
    ${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/test/*.c
)

add_custom_target(
    check
    COMMAND cppcheck ${CPPCHECK_ARGS}
    COMMENT "running cppcheck"
)
