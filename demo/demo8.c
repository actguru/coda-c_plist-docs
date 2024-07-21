	#include "demo.h"

static char code[]="8",desc[]="A Dictionary of Plists.";

int demo8() {

	char *file="plist1.plist";
	printf("Loading: %s\n",file);
	Dictionary plist1=PList_Load(file,0);
	if (!plist1) quit("Error loading file(%s): %s\n",file,OError());

	char *file5="plist5.plist";
	printf("Loading: %s\n",file5);
	Dictionary plist5=PList_Load(file5,0);
	if (!plist5) quit("Error loading file(%s): %s\n",file5,OError());

	char *file7="plist7.plist";
	printf("Loading: %s\n",file7);
	Dictionary plist7=PList_Load(file7,0);
	if (!plist7) quit("Error loading file(%s): %s\n",file7,OError());

	Dict dict=newO(Dict);
	Dict_take(dict,"plist1",plist1);
	Dict_take(dict,"plist5",plist5);
	Dict_take(dict,"plist7",plist7);


	char *ofile="plist8.plist";
	if (!PList_save(ofile,dict,PLIST_Apple))
		quit("Error saving file(%s): %s\n",ofile,OError());
	printf("Saved modified plist to file: %s\n",ofile);

	printf("\n");
	printf("diagnostic: %s\n",ToContainer(dict));

	return(0);
	}

static void __attribute__((constructor)) boot() { register_demo(code,desc,demo8); }

