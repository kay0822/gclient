#include <stdio.h>
#include <locale.h>
#include <libintl.h>

#define _(S) gettext(S)

#define PACKAGE "test1"

int main(){
  setlocale(LC_ALL, "");
  bindtextdomain(PACKAGE, "locale");
  textdomain(PACKAGE);

  printf(_("Hello,GetText!\n"));
  printf(_("haha"));
  return 0;
}
