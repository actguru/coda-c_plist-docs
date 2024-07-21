	#include "demo.h"

static char code[]="2",desc[]="Show some serialization formats.";

int demo2() {

	Char string=Char_Value("A string.");

	printf("Apple XML Property List\n");
	PList_toStream(stdout,string,PLIST_Apple);
	printf("-------------------------------------------------------\n");
	printf("Apple XML Property List without headers & version\n");
	PList_toStream(stdout,string,PLIST_Apple | PLIST_NoEncoding | PLIST_NoDoctype | PLIST_NoPVersion);
	printf("-------------------------------------------------------\n");
	printf("Coda-C XML Property List\n");
	PList_toStream(stdout,string,0);
	printf("-------------------------------------------------------\n");

	return(0);
	}

static void __attribute__((constructor)) boot() { register_demo(code,desc,demo2); }

