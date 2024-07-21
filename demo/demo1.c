	#include "demo.h"

static char code[]="1",desc[]="Create a Dictionary that contains an object for each plist class.";

int demo1() {
	Array aa=newO(Array);
	Array_addObject(aa,Os("Green"));
	Array_add(aa,Os("Red"));

	Dictionary dd=newO(Dictionary);
	Dictionary_takeKey(dd,"Colors",aa);
	Dictionary_takeKey(dd,"Number",Huge_Value(1234));
	Dictionary_takeKey(dd,"Rate",  Real_Value(1.234));
	Dictionary_takeKey(dd,"Flag",  Bool_Value(1));
		char raw[]="\x0A\xFFRaw\001";
	Dict_take(dd,"Raw data",Data_NewBlock(0,sizeof(raw)-1,raw));
	Dict_take(dd,"Date",DateString_Value("2024-12-01T01:02:03Z"));
	Dict_take(dd,"SubDict",newO(Dictionary));

	PList_toStream(stdout,dd,PLIST_Apple | PLIST_NoEncoding | PLIST_NoDoctype);
	printf("-------------------------------------------------------\n");
	printf("diagnostic = %s\n",ToContainer(dd)); // ++leak
	char *file="plist1.plist";
	if (!PList_save(file,dd,PLIST_Apple))
		quit("Error saving file(%s): %s\n",file,OError());
	printf("Saved file: %s\n",file);
	return(0);
	}

static void __attribute__((constructor)) boot() { register_demo(code,desc,demo1); }

