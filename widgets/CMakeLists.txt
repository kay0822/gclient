set(LIBRARY_NAME  ${PROJECT_NAME}-widget)

add_library(${LIBRARY_NAME} widget.c)

install(TARGETS ${LIBRARY_NAME} DESTINATION lib)

