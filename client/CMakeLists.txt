
add_executable (${PROJECT_NAME}  gclient.c)
if(GTK2_FOUND)
	include_directories(${GTK2_INCLUDE_DIRS})
	target_link_libraries(${PROJECT_NAME}  ${GTK2_LIBRARIES})
endif(GTK2_FOUND)

target_link_libraries(${PROJECT_NAME}  ${PROJECT_NAME}-core)
target_link_libraries(${PROJECT_NAME}  ${PROJECT_NAME}-widget)

