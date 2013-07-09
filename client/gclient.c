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
	GdkScreen *screen = gdk_screen_get_default();
	gint width = gdk_screen_get_width(screen);
    gint height = gdk_screen_get_height(screen);

	/* Background */
	//TODO

	/* Menu */
	GtkWidget *fixed, *vbox, *menubar, *filemenu, *file, *new;
	GtkWidget *menustart, *menuitem;

#if 1
	fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);

	menubar = gtk_menu_bar_new();
	gint _WIDTH = 500, _HEIGHT = 20;
	gtk_fixed_put(GTK_FIXED(fixed), menubar, 0, height - _HEIGHT);
	gtk_widget_set_size_request(menubar, _WIDTH, _HEIGHT); 

	menustart = gtk_menu_item_new_with_label("start");
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menustart);

	menuitem = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menustart), menuitem);

	GtkWidget *browser, *protocol, *ica, *rdp, *menuitem2;
	browser = gtk_menu_item_new_with_label("browser");
	protocol = gtk_menu_item_new_with_label("protocol");
	gtk_menu_shell_append(GTK_MENU_SHELL(menuitem), browser);
	gtk_menu_shell_append(GTK_MENU_SHELL(menuitem), protocol);


	menuitem2 = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(protocol), menuitem2);
	ica = gtk_menu_item_new_with_label("ICA");
	rdp = gtk_menu_item_new_with_label("RDP");
	gtk_menu_shell_append(GTK_MENU_SHELL(gtk_menu_item_get_submenu(GTK_MENU_ITEM(protocol))), ica);
	gtk_menu_shell_append(GTK_MENU_SHELL(gtk_menu_item_get_submenu(GTK_MENU_ITEM(protocol))), rdp);
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





