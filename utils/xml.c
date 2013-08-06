/*
 * parse xml
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

#include <common.h>

/**
 * test_parse
 * just for test
 */
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

/**
 * xml_get_string_by_node
 * @node: 		a xmlNodePtr
 * @xmlString: 	a string of the content of node
 *
 * Returns:	the number of bytes written to the xmlString or -1 in case of error
 */
int xml_get_string_by_node(xmlNodePtr node, char** xmlString){
	assert(node);
	xmlBufferPtr buf = xmlBufferCreate();
	int size = 0;
	switch(node->type){
		case XML_ELEMENT_NODE:
			size = xmlNodeDump(buf, NULL, node, 0, 1);
			break;
		case XML_ATTRIBUTE_NODE:
			size = xmlNodeDump(buf, NULL, node->parent, 0, 1);
			break;
		case XML_NAMESPACE_DECL:
		default:
			ERROR("type invalid: %d\n", node->type);
			xmlBufferFree(buf);
			return -1;
	}
	const char* content = xmlBufferContent(buf);
	*xmlString = (char*)malloc( size );
	strcpy(*xmlString, content);
	xmlBufferFree(buf);
	return size;
}

/**
 * xml_get_strings_by_xpath
 * @filename: 	input xml filename
 * @xpath:		xpath 
 * @value:		value of xpath, if the type of xpath is node, should be ignored
 * @string_num: number of string
 * @xmlStrings:	an array of xmlString of the xmlNode with specific xpath
 *
 * Returns: 0 if success
 */
int xml_get_strings_by_xpath(const char* filename, const char* xpath, const char* value, int* string_num, char* (*xmlStrings)[]){
	assert(filename);
	assert(xpath);
	
	xmlDocPtr doc;
	xmlXPathContextPtr xpathCtx; 
	xmlXPathObjectPtr xpathObj; 
	
	doc = xmlParseFile(filename);
	if (doc == NULL) {
		ERROR("unable to parse file: %s\n", filename);
		return(-1);
	}
	
	xpathCtx = xmlXPathNewContext(doc);
	if(xpathCtx == NULL) {
		ERROR("unable to create new XPath context\n");
		xmlFreeDoc(doc); 
		return(-1);
	}
	
	xpathObj = xmlXPathEvalExpression(xpath, xpathCtx);
	if(xpathObj == NULL) {
		ERROR("unable to evaluate xpath expression \"%s\"\n", xpath);
		xmlXPathFreeContext(xpathCtx); 
		xmlFreeDoc(doc); 
		return(-1);
	}
	
	xmlNodeSetPtr nodes = xpathObj->nodesetval;
	int size = (nodes) ? nodes->nodeNr : 0;
	*string_num = size;
	int i;
	char** strings;
	strings = *xmlStrings;
	for(i = 0; i < size; i++) {
		int length = 0;
		char* xmlString;
		int size = xml_get_string_by_node(nodes->nodeTab[i], &xmlString);
		if(size == -1) {
			return -1;
		}
		*(strings + i) = xmlString;
	}

	xmlXPathFreeObject(xpathObj);
	xmlXPathFreeContext(xpathCtx); 
	xmlFreeDoc(doc); 
	
	return(0);
}  

#if 0
void xml_dump_node(xmlNode*, char* xmlString){
	
}

void xml_get_root_element(xmlDoc* doc, xmlNode* root){
	xmlNode* root = xmlDocGetRootElement(doc);
	if (root == NULL) {
        ERROR("empty document\n");
        xmlFreeDoc(doc);
        return;
    }
}

void xml_get_doc(const *char filename, xmlDoc* doc){
	LIBXML_TEST_VERSION

	doc = xmlParseFile(filename);
	if (doc == NULL) {
        ERROR("failed to parse %s\n", filename);
        return;
    }
}

#endif
