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
	xmlInitParser();
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
#if 0
	if ((!xmlStrcmp(cur->name, (const xmlChar *)"root"))) {
		xmlChar *key;
		key = xmlNodeListGetString(doc, cur->children, 0);
		printf("keyword: %s\n", key);
		xmlFree(key);
	}
#endif
	parseNode(cur);
	//xmlBufferPtr buf;
	xmlBufferPtr buf = xmlBufferCreate();
	int size = xmlNodeDump(buf, NULL, cur, 0, 0);
	//printf("%s\n", buf->content);
	printf("%s\n", xmlBufferContent(buf));

	xmlBufferFree(buf);
	
	//printf("%s\n", xmlXPathCastNodeToString(doc));

	xmlFreeDoc(doc);
	xmlCleanupParser();
	return;
}
