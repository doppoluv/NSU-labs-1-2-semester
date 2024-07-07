if(WIN32)
	set(EXE ".exe")
endif(WIN32)

set(TEST_RUNNER_NAME "test${PROJECT_NAME}${EXE}")
set(TEST_RUNNER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/test/${TEST_RUNNER_NAME})

math(EXPR UNLIMITED_MS 60*1000)
math(EXPR UNLIMITED_KB 1024*1024)
option(UNLIMITED "Disable time/memory limits" OFF)

include(valgrind)

include (CTest)
enable_testing()

if (UNLIMITED)
	add_test(
		NAME ${TEST_RUNNER_NAME}
		COMMAND ${TEST_RUNNER_PATH} -m ${UNLIMITED_KB} -t ${UNLIMITED_MS} ./${PROJECT_NAME}
	)
else()
	add_test(
		NAME ${TEST_RUNNER_NAME}
		COMMAND ${TEST_RUNNER_PATH} ./${PROJECT_NAME}
	)
endif()

set_tests_properties(${TEST_RUNNER_NAME} PROPERTIES DEPENDS ${PROJECT_NAME})
