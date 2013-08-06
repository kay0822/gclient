/**
 * gclient program
 */
#include <stdio.h>

#include <gclient.h>
#include <widgets/widget.h>
#include <core/gtk.h>

//#include <cairo.h>

GtkBuilder *builder;

gboolean show(GtkWidget* widget, GdkEventKey * event, gpointer data){
	DEBUG("\n");
	gtk_menu_item_select (GTK_MENU_ITEM(widget));
	gtk_widget_show_all(widget);
	return TRUE;
}

gboolean destroy(GtkWidget* widget, gpointer data){
	DEBUG("\n");
	g_object_unref(G_OBJECT(builder));
	gtk_main_quit ();
}

gboolean ica_callback(GtkWidget* widget, GdkEventKey* event, gpointer data){
	GtkWidget * dialog;
	/**************
	char xmlname[128];
	MEMZERO(xmlname);
	gtk_builder_add_from_file(builder, XML(dialog.xml), &err);
	**************/
	char* xmlStrings[MAX_XML_STRINGS_SIZE];
	int i, num = 0; 
#if 1
	int ret = xml_get_strings_by_xpath(XML(dialog.xml), "//interface", NULL, &num, &xmlStrings);
	if(ret != 0) {
		ERROR("ret = %d\n", ret);	
	}
	for( i = 0; i < num; i++){
		DEBUG("\n%s\n", *(xmlStrings + i));
		GError *err = NULL;
		gtk_builder_add_from_string(builder, *(xmlStrings+i), strlen(*(xmlStrings+i)) , &err);
		if(err != NULL) {
			WARN("dialog.xml is invalid, code=%d, msg=%s\n", err->code, err->message);
		}
		free( *(xmlStrings + i) );
	}
#else
	const gchar* str = "   <interface><object class=\"GtkDialog\" id=\"dialog1\"><child internal-child=\"vbox\"><object class=\"GtkVBox\" id=\"vbox1\"><property name=\"border-width\">10</property><child internal-child=\"action_area\"><object class=\"GtkHButtonBox\" id=\"hbuttonbox1\"><property name=\"border-width\">20</property><child><object class=\"GtkButton\" id=\"ok_button\"><property name=\"label\"  translatable=\"yes\">gtk-ok</property><!--property name=\"use-stock\">TRUE</property--><signal name=\"clicked\" handler=\"ok_button_clicked\"/></object></child></object></child></object></child></object></interface>";
	gtk_builder_add_from_string(builder, str, strlen(str), NULL);
#endif
	dialog=GTK_WIDGET(gtk_builder_get_object(builder,"dialog1"));
	//g_object_unref(G_OBJECT(builder)); /* builder should be a global variable */
	gtk_widget_show_all(dialog);

#if 0
	DEBUG_MSG("\n");
	GtkWidget *dialog_ica;
	//dialog_ica = gtk_window_new (GTK_WINDOW_POPUP);
	//dialog_ica = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	//dialog_ica = gtk_dialog_new ();
	dialog_ica = gtk_dialog_new_with_buttons("My", NULL, 
							GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT|GTK_DIALOG_NO_SEPARATOR,
							_("OK"), GTK_RESPONSE_ACCEPT,
							GTK_STOCK_CANCEL, GTK_RESPONSE_REJECT,
							NULL); 
	gtk_window_set_title (GTK_WINDOW (dialog_ica), "Citrix ICA");
	gtk_window_set_position( GTK_WINDOW(dialog_ica), GTK_WIN_POS_CENTER_ALWAYS );
	gtk_container_set_border_width (GTK_CONTAINER (dialog_ica), 0);
    gtk_widget_set_size_request (dialog_ica, 400, 320);
	gtk_window_set_frame_dimensions(GTK_WINDOW(dialog_ica), 20, 20, 20, 20);

/*
	GtkWidget *fixed = gtk_fixed_new ();
    gtk_container_add (GTK_CONTAINER (dialog_ica), fixed);
	GtkWidget *labelCitrixr = gtk_label_new ("ICA ");
    gtk_fixed_put(GTK_FIXED(fixed), labelCitrixr, 35, 20);
*/
	gtk_window_set_modal(GTK_WINDOW(dialog_ica), TRUE);
//	gtk_widget_show_all(dialog_ica);
	int flag = 1;
	while(flag){
		gint result = gtk_dialog_run(GTK_DIALOG(dialog_ica));  /* 可以阻断delete-event, 和response ， 貌似就一次？*/
		switch (result)
		{
			case GTK_RESPONSE_ACCEPT:
				break;
			default:
				flag = 0;
         		break;
    	}

		DEBUG_MSG("%d\n", result);
	}
	gtk_widget_destroy(dialog_ica);
g_signal_connect_swapped (dialog_ica,
                             "response", 
                             G_CALLBACK (gtk_widget_destroy),
                             dialog_ica); /* 确保用户响应之后，dialog关闭 */
#endif
}

do_test(){
	/* Just test widget */
	test_widget();

	/* Just test utils */
	test_parse();

	test_i18n();
}

int main(int argc, char* argv[]){

	/* Start */
	DEBUG_MSG("I'm gclient!\n");

	i18n_init();

	/* test */
	do_test();

#if 1 /* GtkBuilder */
	DEBUG_MSG("GtkBuilder ...\n");
	gtk_init (&argc, &argv);
	GtkWidget * window;
	//GtkBuilder *builder;
    builder = gtk_builder_new();
    gtk_builder_set_translation_domain(builder, GETTEXT_PACKAGE);
	GError *err = NULL;
	char xmlname[128];
	MEMZERO(xmlname);
	sprintf(xmlname, "%s/xml/window.xml", PACKAGE_INSTALL_PREFIX);
    gtk_builder_add_from_file(builder, xmlname, &err);
	if(err != NULL){
		ERROR("window.xml is invalid, code=%d, msg=%s\n", err->code, err->message);
	}

    window=GTK_WIDGET(gtk_builder_get_object(builder,"desktop"));

	/*  background */
	GtkWidget *background = GTK_WIDGET(gtk_builder_get_object(builder,"background"));
	GdkPixmap *pixmap;
	GdkPixbuf *pixbuf; 
	GtkStyle *style;
	pixbuf = gtk_image_get_pixbuf(GTK_IMAGE(background));
	gdk_pixbuf_render_pixmap_and_mask (pixbuf, &pixmap, NULL, 0); 
	style = gtk_style_new (); 
	style->bg_pixmap[0] = pixmap; 
	gtk_widget_set_style (GTK_WIDGET(window), GTK_STYLE(style)); 


	/*  screen  */
	GdkScreen *screen = gdk_screen_get_default();
	gint width = gdk_screen_get_width(screen);
    gint height = gdk_screen_get_height(screen);
	gtk_widget_set_size_request(window, width, height);

	gtk_container_set_border_width(GTK_CONTAINER(window), 0);
	gtk_widget_realize(window);
	gtk_window_fullscreen(GTK_WINDOW(window));
	gtk_builder_connect_signals (builder, NULL);

//	g_object_unref(G_OBJECT(builder)); /*put it in destroy*/

    gtk_widget_show_all(window);
	gtk_main();
#else	 /* GtkBuilder */

	/* Initial */
	GtkWidget *window;
	window = gclient_init(argc, argv);
	GdkScreen *screen = gdk_screen_get_default();
	gint width = gdk_screen_get_width(screen);
    gint height = gdk_screen_get_height(screen);


	/* Background */
	//TODO

	/* Menu */
	GtkWidget *fixed, *vbox;
	GtkWidget *menubar, *menubar2, *filemenu, *file, *new;
	GtkWidget *menustart, *menustart2;
	GtkWidget *menu, *menu2;
	GtkWidget *browser, *protocol, *quit, *ica, *rdp;
	GtkAccelGroup *accel_group = NULL;

#if 1

#if 0
	fixed = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), fixed);

	menubar = gtk_menu_bar_new();
	gint _WIDTH = 500, _HEIGHT = 20;
	gtk_fixed_put(GTK_FIXED(fixed), menubar, 0, height - _HEIGHT);
	gtk_widget_set_size_request(menubar, _WIDTH, _HEIGHT); 
#else
	vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_border_width(GTK_CONTAINER(vbox), 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);
	menubar = gtk_menu_bar_new();
	gint _WIDTH = 500, _HEIGHT = 30;
	gtk_box_pack_end(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
	gtk_widget_set_size_request(menubar, _WIDTH, _HEIGHT);
//	menubar2 = gtk_menu_bar_new();
//	gtk_box_pack_end(GTK_BOX(vbox), menubar2, FALSE, FALSE, 1);
//	gtk_widget_set_size_request(menubar2, _WIDTH, _HEIGHT);
#endif

	accel_group = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

	menustart = gtk_menu_item_new_with_label(_("Start"));
	gtk_widget_set_tooltip_markup (menustart, _("<b>START</b>"));
	//menustart = gtk_menu_item_new_with_mnemonic("_start");
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


	menu = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menustart), menu);

	browser = gtk_menu_item_new_with_label(_("Browser"));
	protocol = gtk_menu_item_new_with_label(_("Protocol"));
	quit = gtk_menu_item_new_with_label(_("Quit"));
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), browser);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), protocol);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), quit);
	//gtk_widget_add_accelerator(protocol, "activate", accel_group, GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
	gtk_widget_add_accelerator(menustart, "activate", accel_group, GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

	menu2 = gtk_menu_new();
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(protocol), menu2);
	ica = gtk_menu_item_new_with_label(_("ICA"));
	rdp = gtk_menu_item_new_with_label(_("RDP"));
	gtk_menu_shell_append(GTK_MENU_SHELL(gtk_menu_item_get_submenu(GTK_MENU_ITEM(protocol))), ica);
	gtk_menu_shell_append(GTK_MENU_SHELL(gtk_menu_item_get_submenu(GTK_MENU_ITEM(protocol))), rdp);


	g_signal_connect(G_OBJECT(menustart), "activate", G_CALLBACK(show), NULL);

	g_signal_connect(G_OBJECT(ica), "activate", G_CALLBACK(ica_callback), NULL);
	g_signal_connect(G_OBJECT(quit), "activate", G_CALLBACK(destroy), NULL);
#endif
	
	gtk_widget_show_all(window);
	gtk_main();

#endif  /* GtkBuilder */
}





