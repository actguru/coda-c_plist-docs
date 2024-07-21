	#include "demo.h"

static char code[]="6",desc[]="Merge two Dictionaries.";

int demo6() {

	Dictionary d1=newO(Dictionary);
	Dict_take(d1,"Grape",Os("red"));
	Dict_take(d1,"Banana",Os("yellow"));
	Dict_take(d1,"Kiwi",Os("green"));
	Dict_take(d1,"Orange",Os("orange"));

	char *ifile="plist1.plist";
	printf("Loading: %s\n",ifile);
	Dictionary dict=PList_Load(ifile,0); // new object
	if (!dict) quit("Error loading file(%s): %s\n",ifile,OError());

	for(Keyword key=Dictionary_scan(dict);key;key=Dictionary_next(key)) {
		Dict_set(d1,key->word,key->item);
		}

	char *ofile="plist6.plist";
	if (!PList_save(ofile,d1,PLIST_Apple))
		quit("Error saving file(%s): %s\n",ofile,OError());
	printf("Saved modified plist to file: %s\n",ofile);

	printf("\n");
	PList_toStream(stdout,d1,PLIST_Apple | PLIST_NoEncoding | PLIST_NoDoctype);

	printf("\n");
	printf("finish testing\n");
	printf("diagnostic: %s\n",ToContainer(d1));

	return(0);
	}

static void __attribute__((constructor)) boot() { register_demo(code,desc,demo6); }

