
file(GLOB PROJECT_HEADERS "*.h") 
install(FILES ${PROJECT_HEADERS} DESTINATION include COMPONENT headers)

#install(DIRECTORY freerdp/cache DESTINATION include/freerdp COMPONENT headers FILES_MATCHING PATTERN "*.h")

