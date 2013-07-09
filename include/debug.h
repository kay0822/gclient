#ifndef __DEBUG_H__
#define __DEBUG_H__

#define DEBUG_NULL(fmt, ...) 						do{}while(0)
//#define DEBUG_PRINT(_string, fmt, ...) 	fprintf(stderr, _string fmt "\n", __FUNCTION__, __LINE__, ## __VA_ARGS__)
#define DEBUG_PRINT(_dbg_class, _string, fmt, ...) 	fprintf(stderr, "[%-12s]" _string fmt, _dbg_class, __FUNCTION__, __LINE__, ## __VA_ARGS__)
#define DEBUG_CLASS(_class, fmt, ...)				DEBUG_PRINT("DBG_" #_class, "%-15s (%03d): ", fmt, ## __VA_ARGS__)
#define DEBUG_WARN(fmt, ...) 						DEBUG_PRINT("Warning %s (%d): ", fmt, ## __VA_ARGS__)

#ifdef WITH_DEBUG
#define DEBUG_MSG(fmt, ...) 						DEBUG_CLASS(MSG, fmt, ## __VA_ARGS__)
#else
#define DEBUG_MSG(fmt, ...)							DEBUG_NULL(fmt, ## __VA_ARGS__)
#endif

#endif
