targets10= test_widget
targets9 = test_textview test_line_column test_search_highlight
targets8 = test_listview_simple test_listview_advanced test_treeview
targets7 = test_combobox test_h_separator test_entry test_image test_statusbar test_icon_view
targets6 = test_button test_checkbox test_frame test_label test_label_markup
targets5 = test_dialog_msg test_dialog_about test_dialog_fontselect test_dialog_colorselect
targets4 = test_click test_move test_enter test_disconnect_callback test_drag_drop test_timer
targets3 = test_fixed test_vbox test_table test_alignment test_window
targets2 = test_menu test_menus test_check_menu test_toolbar test_undo_redo
targets1 = test1 test_center test_icon test_increase_decrease
targets = $(targets1) $(targets2) $(targets3) $(targets4) $(targets5) $(targets6) $(targets7) $(targets8) $(targets9) $(targets10)

all: $(targets)
clean:
	rm -f $(targets) *.o

CFLAG_GTK = `pkg-config --libs --cflags gtk+-2.0`
CFLAGS = -g $(CFLAG_GTK)


test_widget: test_widget.o cpu.o
	gcc -o $@ $? $(CFLAGS)
	

