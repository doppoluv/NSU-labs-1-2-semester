include(enable_warnings)
include(cpp_check)
include(test_runner)
include(enable_sanitizers)
include(use_C99)
include(with_math)

target_compile_definitions(${PROJECT_NAME} PRIVATE __USE_MINGW_ANSI_STDIO=1)
