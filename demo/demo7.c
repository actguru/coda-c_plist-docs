	#include "demo.h"

static char code[]="7",desc[]="Unserialize a memory block.";

int demo7() {

	char *info=" <plist> <array> <string>Red</string> <string>Green</string>"
		" <string>Blue</string> </array> </plist>";

	Array aa=Json_FromBlock(strlen(info),info,0);
	assert(aa);

	char *ofile="plist7.plist";
	if (!Json_save(ofile,aa,PLIST_Json))
		quit("Error saving file(%s): %s\n",ofile,OError());
	printf("Saved modified plist to file: %s\n",ofile);

	printf("\n");
	printf("diagnostic: %s\n",ToContainer(aa));

	return(0);
	}

static void __attribute__((constructor)) boot() { register_demo(code,desc,demo7); }

