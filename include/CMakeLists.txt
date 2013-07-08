
file(GLOB PROJECT_HEADERS "*.h") 
install(FILES ${PROJECT_HEADERS} DESTINATION include COMPONENT headers)

install(DIRECTORY core 		DESTINATION include/core 		COMPONENT headers FILES_MATCHING PATTERN "*.h")
install(DIRECTORY widgets 	DESTINATION include/widgets		COMPONENT headers FILES_MATCHING PATTERN "*.h")

