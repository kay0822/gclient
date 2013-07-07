

add_executable (gclient gclient.c)
if(GTK2_FOUND)
	include_directories(${GTK2_INCLUDE_DIRS})
	target_link_libraries(gclient ${GTK2_LIBRARIES})
endif(GTK2_FOUND)
