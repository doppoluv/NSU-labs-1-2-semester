find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
	target_link_libraries(${PROJECT_NAME} PUBLIC ${MATH_LIBRARY})
endif()
