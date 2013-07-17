#include <stdio.h>

#include <gclient.h>
#include <widgets/widget.h>
#include <core/gtk.h>

//#include <cairo.h>
gboolean show(GtkWidget* widget, GdkEventKey * event, gpointer data){
	DEBUG_MSG("start clicked\n");
	return TRUE;
}

gboolean key_value(GtkWidget* widget, GdkEventKey * event, gpointer data){
	guint keyvalue = event->keyval;
	DEBUG_MSG("%d \n", keyvalue);
	return TRUE;
}

int main(int argc, char* argv[]){

	/* Start */
	DEBUG_MSG("I'm gclient!\n");

	/* Initial */
	GtkWidget *window;
	window = gclient_init(argc, argv);
	GdkScreen *screen = gdk_screen_get_default();
	gint width = gdk_screen_get_width(screen);
    gint height = gdk_screen_get_height(screen);

	i18n_init();

	/* Just test widget */
	test_widget();

	/* Just test utils */
	test_parse();

	test_i18n();

	/* Background */
	//TODO

	/* Menu */
	GtkWidget *fixed, *vbox, *menubar, *filemenu, *file, *new;
	GtkWidget *menustart, *menuitem;
	GtkWidget *menustart2;
	GtkWidget *browser, *protocol, *quit, *ica, *rdp, *menuitem2;
	GtkAccelGroup *accel_group = NULL;

#if 1
	fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);

	menubar = gtk_menu_bar_new();
	gint _WIDTH = 500, _HEIGHT = 20;
	gtk_fixed_put(GTK_FIXED(fixed), menubar, 0, height - _HEIGHT);
	gtk_widget_set_size_request(menubar, _WIDTH, _HEIGHT); 

	vbox = gtk_vbox_new(FALSE, 1);
	gtk_container_border_width(GTK_CONTAINER(vbox), 1);
	//gtk_container_add(GTK_CONTAINER(window), protocol	
	accel_group = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

	//menustart = gtk_menu_item_new_with_label("start");
	menustart = gtk_menu_item_new_with_mnemonic("_start");
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menustart);
	menustart2 = gtk_menu_item_new_with_label("start2");
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menustart2);

/*
	GtkWidget *statusbar;
	statusbar = gtk_statusbar_new();
	gtk_statusbar_set_has_resize_grip(GTK_STATUSBAR(statusbar), FALSE);
	gtk_fixed_put(GTK_FIXED(fixed), statusbar, 0, height - _HEIGHT - 30);
	gtk_widget_set_size_request(statusbar, width, 30);
DEBUG_MSG("gtk_statusbar_get_context_id = %d\n", gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), "test"));
	gtk_statusbar_push(GTK_STATUSBAR(statusbar), 10, "test");
	//gtk_statusbar_push(GTK_STATUSBAR(statusbar), gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), "test"), "test");
*/

/*
	GtkWidget* entry = gtk_entry_new();
	gtk_fixed_put(GTK_FIXED(fixed), entry, 0, 300);
	g_signal_connect(entry, "key-press-event", G_CALLBACK(key_value), NULL);
*/	

	menuitem = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menustart), menuitem);

	//browser = gtk_menu_item_new_with_label("browser");
	browser = gtk_image_menu_item_new_with_mnemonic("_browser");
	//protocol = gtk_menu_item_new_with_label("protocol");
	protocol = gtk_menu_item_new_with_mnemonic("_protocol");
	quit = gtk_menu_item_new_with_label("quit");
	gtk_menu_shell_append(GTK_MENU_SHELL(menuitem), browser);
	gtk_menu_shell_append(GTK_MENU_SHELL(menuitem), protocol);
	gtk_menu_shell_append(GTK_MENU_SHELL(menuitem), quit);
	//gtk_widget_add_accelerator(protocol, "activate", accel_group, GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(menustart, "activate", accel_group, GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

	menuitem2 = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(protocol), menuitem2);
	ica = gtk_menu_item_new_with_label("ICA");
	rdp = gtk_menu_item_new_with_label("RDP");
	gtk_menu_shell_append(GTK_MENU_SHELL(gtk_menu_item_get_submenu(GTK_MENU_ITEM(protocol))), ica);
	gtk_menu_shell_append(GTK_MENU_SHELL(gtk_menu_item_get_submenu(GTK_MENU_ITEM(protocol))), rdp);


	g_signal_connect(G_OBJECT(menustart), "activate", G_CALLBACK(show), NULL);
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





