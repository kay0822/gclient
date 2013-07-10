#ifndef __CORE_GTK_H__
#define __CORE_GTK_H__

#include <common.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

#ifdef WITH_DEBUG_GTK
#define DEBUG_GTK(fmt, ...) DEBUG_CLASS(GTK, fmt, ## __VA_ARGS__)
#else
#define DEBUG_GTK(fmt, ...) DEBUG_NULL(fmt, ## __VA_ARGS__)
#endif

GtkWidget* gclient_init(int argc, char* argv[]);

#endif
