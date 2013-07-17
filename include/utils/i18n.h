#ifndef __UTILS_I18N_H__
#define __UTILS_I18N_H__

#include <common.h>
#include <glib/gi18n-lib.h>

#ifdef WITH_DEBUG_I18N
#define DEBUG_I18N(fmt, ...) DEBUG_CLASS(I18N, fmt, ## __VA_ARGS__)
#else
#define DEBUG_I18N(fmt, ...) DEBUG_NULL(fmt, ## __VA_ARGS__)
#endif

#endif
