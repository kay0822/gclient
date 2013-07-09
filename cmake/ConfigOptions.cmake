option(WITH_DEBUG_ALL "Print all debug messages." OFF)

if(WITH_DEBUG_ALL)
	set(DEFAULT_DEBUG_OPTION "ON")
else()
	set(DEFAULT_DEBUG_OPTION "OFF")
endif()

option(WITH_DEBUG_GTK 		"Print GTK related messages." 		${DEFAULT_DEBUG_OPTION})
option(WITH_DEBUG_WIDGET 	"Print widgets related messages."	${DEFAULT_DEBUG_OPTION})


