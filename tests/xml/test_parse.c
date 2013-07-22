#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

void parseNode(xmlNode* node){
	xmlNode* cur = NULL;
	for(cur = node; cur != NULL; cur = cur->next){
		if(cur->type == XML_ELEMENT_NODE){
			printf("name: %s\n", cur->name);
		}
		else if(cur->type == XML_TEXT_NODE){
			printf("text: %s\n", cur->name);
		}
		else{
			fprintf(stderr, "ERROR, type: %d\n", cur->type);
		}
		parseNode(cur->children);
	}
}

int main(int argc, char** argv){
	LIBXML_TEST_VERSION
	
	xmlDoc* 	doc = NULL;
	xmlNode* 	cur = NULL;
	const char* filename = "test.xml";
	doc = xmlParseFile(filename);

	if (doc == NULL) {
        fprintf(stderr, "Failed to parse %s\n", filename);
		return;
    }

	cur = xmlDocGetRootElement(doc);
	if (cur == NULL) {
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
		return;
	}
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"root"))) {
		xmlChar *key;
		key = xmlNodeListGetString(doc, cur->children, 1);
		printf("keyword: %s\n", key);
		xmlFree(key);
	}
	parseNode(cur);

	xmlFreeDoc(doc);
	xmlCleanupParser();
	return;
}
