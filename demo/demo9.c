	#include "demo.h"

static char code[]="9",desc[]="Extract a container from existing plist.";

int demo9() {

	Object_Leaks(); // will report leak count @ return

	char *file="plist8.plist";
	printf("Loading: %s\n",file);
	Dictionary plist8=PList_Load(file,0);
	if (!plist8) quit("Error loading file(%s): %s\n",file,OError());

		{ // block reduces scope of cleanO attribute
		cleanO Dict dict=Dict_sub(plist8,"plist5"); assert(dict); // freeO(dict) deferred
		keepO(dict); // retain this branch

		freeO(plist8); // destroy loaded plist

		char *ofile="plist9.plist"; // same as plist5, I hope!
		if (!PList_save(ofile,dict,PLIST_Apple))
			quit("Error saving file(%s): %s\n",ofile,OError());
		printf("Saved modified plist to file: %s\n",ofile);

		printf("\n");
		cleanO Char msg=ToContainer(dict); // freeO(msg) -- end scope
		printf("diagnostic: %s\n",msg);
		}

	return(0);
	}

static void __attribute__((constructor)) boot() { register_demo(code,desc,demo9); }

