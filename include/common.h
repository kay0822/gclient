#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <debug.h>

#ifdef WITH_I18N
#include <utils/i18n.h>
#endif

/* M E M */
#define MEMZERO(obj)  memset(obj, 0, sizeof(obj))

/*  L O G  */
#include <stdarg.h>
#ifdef WITH_DEBUG
#define ERROR(fmt, ...) LOGGING(stderr, [ERROR], fmt, ##__VA_ARGS__)
#define WARN(fmt, ...)  LOGGING(stdout, [WARN],  fmt, ##__VA_ARGS__)
#define INFO(fmt, ...)  LOGGING(stdout, [INFO],  fmt, ##__VA_ARGS__)
#define LOGGING(f, type, fmt, ...) fprintf(f, #type " %s %s (%3d):" fmt, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define LOG_FILE  "/var/log/gclient/g.log"
#define ERROR(fmt, ...) LOGGING(LOG_FILE, [ERROR], fmt, ##__VA_ARGS__)
#define WARN(fmt, ...)  LOGGING(LOG_FILE, [WARN],  fmt, ##__VA_ARGS__)
#define INFO(fmt, ...)  LOGGING(LOG_FILE, [INFO],  fmt, ##__VA_ARGS__)
#define LOGGING(f, type, fmt, ...) logging(f, #type " " fmt, ##__VA_ARGS__)
int logging(char* filename, char *fmt, ...){
    va_list ap;
    FILE * f = fopen(filename, "a+");
    va_start(ap, fmt);
    vfprintf(f, fmt, ap);
    va_end(ap);
    fclose(f);
}
#endif

#endif
