set(LIBRARY_NAME  ${PROJECT_NAME}-core)

add_library(${LIBRARY_NAME} gtk.c)

if(GTK2_FOUND)
    include_directories(${GTK2_INCLUDE_DIRS})
    target_link_libraries(${LIBRARY_NAME}  ${GTK2_LIBRARIES})
endif(GTK2_FOUND)

install(TARGETS ${LIBRARY_NAME}  DESTINATION  lib)

