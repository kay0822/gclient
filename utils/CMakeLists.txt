set(LIBRARY_NAME  	${PROJECT_NAME}-utils)

set(${LIBRARY_NAME}_SRC 
			xml.c)

if(WITH_I18N)
#	add_definitions(-DGETTEXT_PACKAGE="${PROJECT_NAME}")
#	add_definitions(-DGETTEXT_LOCALEDIR="${CMAKE_INSTALL_PREFIX}/locale")
	set(${LIBRARY_NAME}_SRC ${${LIBRARY_NAME}_SRC} i18n.c)
endif()


add_library(${LIBRARY_NAME}  ${${LIBRARY_NAME}_SRC})

if(LIBXML2_FOUND)
    include_directories(${LIBXML2_INCLUDE_DIR})
    target_link_libraries(${LIBRARY_NAME}  ${LIBXML2_LIBRARIES})
endif(LIBXML2_FOUND)

if(GTK2_FOUND)
    include_directories(${GTK2_INCLUDE_DIRS})
    target_link_libraries(${LIBRARY_NAME}  ${GTK2_LIBRARIES})
endif(GTK2_FOUND)

#set_target_properties(${LIBRARY_NAME} PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_API_VERSION} PREFIX "lib")

install(TARGETS ${LIBRARY_NAME}  DESTINATION  lib)
