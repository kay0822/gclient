
add_library(${PROJECT_NAME}-core SHARED gtk.c)

if(GTK2_FOUND)
    include_directories(${GTK2_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME}-core  ${GTK2_LIBRARIES})
endif(GTK2_FOUND)

