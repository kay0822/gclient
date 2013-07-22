############
# ldconfig #
############
execute_process(COMMAND bash -c "echo ${CMAKE_INSTALL_PREFIX}/lib > ${CMAKE_CURRENT_SOURCE_DIR}/ld/${PROJECT_NAME}.conf")
install(FILES ld/${PROJECT_NAME}.conf  DESTINATION  /etc/ld.so.conf.d)

########
# i18n #
########
execute_process(COMMAND bash -c "cat ${CMAKE_CURRENT_SOURCE_DIR}/locale/zh_CN/*.in > ${CMAKE_CURRENT_SOURCE_DIR}/locale/zh_CN/messages.po")
execute_process(COMMAND msgfmt ${CMAKE_CURRENT_SOURCE_DIR}/locale/zh_CN/messages.po -o ${CMAKE_CURRENT_SOURCE_DIR}/locale/zh_CN/${PROJECT_NAME}.mo)

#install(DIRECTORY locale        DESTINATION share/  COMPONENT headers FILES_MATCHING PATTERN "*.mo"    ) 
install(FILES locale/zh_CN/${PROJECT_NAME}.mo  DESTINATION  locale/zh_CN/LC_MESSAGES)

##########
# images #
##########
install(DIRECTORY images   DESTINATION .)
#install(DIRECTORY images/icons   DESTINATION images)

#######
# xml #
#######
install(DIRECTORY xml  DESTINATION .)
