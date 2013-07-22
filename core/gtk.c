#include <stdio.h>

#include <core/gtk.h>

static void destroy( GtkWidget *widget, gpointer *data )
{
    DEBUG_GTK("destroy event occurred\n");
    gtk_main_quit ();
}

void gclient_append_sep(GtkWidget* menu_item, GtkWidget* sep)
{
	GtkWidget* menu = gtk_menu_item_get_submenu(GTK_MENU_ITEM(menu_item));
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), sep);
}


GtkWidget* gclient_init(int argc, char* argv[]){
    gtk_init (&argc, &argv);
    GdkScreen *screen = gdk_screen_get_default();

    GtkWidget* window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Desktop");
//  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
#if 1
    gint width = gdk_screen_get_width(screen);
    gint height = gdk_screen_get_height(screen);
	DEBUG_GTK("width = %d, height = %d\n", width, height);
    gtk_widget_set_size_request(window, width, height);
#endif
//  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
//  gtk_window_maximize(GTK_WINDOW(window));
    gtk_container_set_border_width(GTK_CONTAINER(window), 0);
    gtk_widget_realize(window);
    gtk_window_fullscreen(GTK_WINDOW(window));

    g_signal_connect (window, "destroy", G_CALLBACK (destroy), NULL);

	return window;
}

