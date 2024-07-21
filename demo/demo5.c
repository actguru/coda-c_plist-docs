	#include "demo.h"

static char code[]="5",desc[]="Modify a Property List. (leak tested)";

int demo5() {
	Object_Leaks(); // scope leak test (diagnostic)

	char *ifile="plist1.plist";
	printf("Loading: %s\n",ifile);
	Dictionary dict=PList_Load(ifile,0); // new object
	if (!dict) quit("Error loading file(%s): %s\n",ifile,OError());

	Dict_set(dict,"Rate",Real_Value(9876.54321)); // oops should have Dict_take() here!!
	Dictionary_removeKey(dict,"Date");

	Array aaa=Dict_sub(dict,"Colors"); assert(isa_(aaa,Array));
	Char magenta=Char_Value("Magenta"); // new object
	Array_insertAt(aaa,1,magenta);
	freeO(magenta); // release

	char *ofile="plist5.plist";
	if (!PList_save(ofile,dict,PLIST_Apple))
		quit("Error saving file(%s): %s\n",ofile,OError());
	printf("Saved modified plist to file: %s\n",ofile);

	printf("\n");
	PList_toStream(stdout,dict,PLIST_Apple | PLIST_NoEncoding | PLIST_NoDoctype);

	printf("\n");
	printf("finish testing\n");

// **** LEAK TESTING NOTES ****
	printf(">>> found 10 leaks... added: freeO(dict)\n");
	printf(">>> found  1 leaks... added: freeO( Dict_sub(dict,\"Rate\"));\n");
	freeO( Dict_sub(dict,"Rate")); // (2) BAD CODE, should be fixed above!!
	freeO(dict); // (1)

	return(0);
	}

static void __attribute__((constructor)) boot() { register_demo(code,desc,demo5); }

