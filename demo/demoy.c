	#include "demo.h"

static char code[]="Y",desc[]="Circular Fault testing.";

int demoY() {

	Dictionary dict=newO(Dictionary);
	Dict_set(dict,"Circle-Test",dict); // looping container

	char *file="plisty.plist";

	printf("\n");
	printf("Trying to save a circular plist, THIS SHOULD FAIL...\n");
	printf("\n");

	if (!PList_save(file,dict,PLIST_Apple))
		quit("Error saving file(%s): %s\n",file,OError()); // THIS SHOULD HAPPEN!!

	printf("WHAT? OOPs? finish testing\n");

	return(0);
	}

static void __attribute__((constructor)) boot() { register_demo(code,desc,demoY); }

