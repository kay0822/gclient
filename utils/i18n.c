#include <utils/i18n.h>

#include <locale.h>

void i18n_init(){
	gtk_set_locale();
	bindtextdomain(GETTEXT_PACKAGE, GETTEXT_LOCALEDIR);
}

void test_i18n(){
	DEBUG_I18N("GETTEXT_PACKAGE: %s\n", GETTEXT_PACKAGE);
	DEBUG_I18N("GETTEXT_LOCALEDIR: %s\n", GETTEXT_LOCALEDIR);
	DEBUG_I18N("%s%s\n", _("Username"), _(":"));

}


