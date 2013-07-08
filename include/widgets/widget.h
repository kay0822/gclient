#ifndef __WIDGETS_WIDGET_H__
#define __WIDGETS_WIDGET_H__

#include <common.h>

#define TEST_WIDGET "widget ok"

#ifdef WITH_DEBUG_WIDGET
#define DEBUG_WIDGET(fmt, ...) DEBUG_CLASS(WIDGET, fmt, ## __VA_ARGS__)
#else
#define DEBUG_WIDGET(fmt, ...) DEBUG_NULL(fmt, ## __VA_ARGS__)
#endif

#endif
