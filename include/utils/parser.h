#ifndef __UTILS_PARSER_H__
#define __UTILS_PARSER_H__

#include <common.h>

#ifdef WITH_DEBUG_PARSER
#define DEBUG_PARSER(fmt, ...) DEBUG_CLASS(PARSER, fmt, ## __VA_ARGS__)
#else
#define DEBUG_PARSER(fmt, ...) DEBUG_NULL(fmt, ## __VA_ARGS__)
#endif

#endif
