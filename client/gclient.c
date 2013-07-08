#include <stdio.h>

#include <gclient.h>
#include <widgets/widget.h>
#include <core/gtk.h>

//#include <cairo.h>

int main(int argc, char* argv[]){
	/* Just test widget */
	test_widget();

	/* Start */
	DEBUG_MSG("I'm gclient!\n");

	/* Initial */
	GtkWidget *window;
	window = gclient_init(argc, argv);
//	GdkScreen *screen = gdk_screen_get_default();
//	gint width = gdk_screen_get_width(screen);
  //  gint height = gdk_screen_get_height(screen);

	/* Background */
	//TODO

	/* Menu */
	GtkWidget *fixed, *vbox, *menubar, *filemenu, *file, *new;
	GtkWidget *menustart, *menuitem;

#if 1
	fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);

	menubar = gtk_menu_bar_new();
	gtk_fixed_put(GTK_FIXED(fixed), menubar, 0, 718);
	gtk_widget_set_size_request(menubar, 100, 50); 

	menustart = gtk_menu_item_new_with_label("start");
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menustart);

	menuitem = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menustart), menuitem);

	GtkWidget* browser;
	browser = gtk_menu_item_new_with_label("browser");
	gtk_menu_shell_append(GTK_MENU_SHELL(menuitem), browser);
#endif
	
#if 0
	GtkAccelGroup * accel_group = NULL;
	vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	filemenu = gtk_menu_new();

	accel_group = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

	file = gtk_menu_item_new_with_label("FILE");
	new = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);
	
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), new);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 1);
#endif
	gtk_widget_show_all(window);
	gtk_main();
}





