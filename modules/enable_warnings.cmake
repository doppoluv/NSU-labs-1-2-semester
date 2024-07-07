if("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
	target_compile_options(${PROJECT_NAME} PRIVATE
            /W4
			/WX)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Werror
            -Wall
            -Wextra
            -Waddress
            -Warray-bounds
            -Wbuiltin-macro-redefined
            -Wswitch
            -Wunreachable-code
            -pedantic
            -pedantic-errors)
endif ()
