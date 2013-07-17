#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

void parse_window(){

}

void test_parse(){
	xmlDocPtr doc;
	xmlNodePtr cur;

	doc = xmlParseFile("/root/git/gclient/utils/window.xml");
	if (doc == NULL) {
		fprintf(stderr,"Document not parsed successfully. \n");
		return;
	}
	
	cur = xmlDocGetRootElement(doc);

	if (cur == NULL) {
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return;
	}

	if (xmlStrcmp(cur->name, (const xmlChar *) "gclient")) {
		fprintf(stderr,"document of the wrong type, root node != gclient\n");
		xmlFreeDoc(doc);
		return;
	}
	
}

