#include <stdio.h>

#include <widget.h>
//#include "widget.h"


#include <gtk/gtk.h>
//#include <cairo.h>

static void destroy( GtkWidget *widget, gpointer *data )
{
    g_print ("destroy event occurred\n");
    gtk_main_quit ();
}

void gclient_init(int argc, char* argv[]){
	gtk_init (&argc, &argv);	
	GdkScreen *screen = gdk_screen_get_default();

	GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gint width = gdk_screen_get_width(screen);
    gint height = gdk_screen_get_height(screen);
	gtk_widget_set_size_request(window, 800, 500);	
	g_signal_connect (window, "destroy", G_CALLBACK (destroy), NULL);
}

int main(int argc, char* argv[]){
	gclient_init(argc, argv);
	printf("I'm gclient!\n");
	gtk_main();
	
}
