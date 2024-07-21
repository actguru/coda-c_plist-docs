	#include "demo.h"

static char code[]="3",desc[]="Validate Dictionary values with isa_().";

int demo3() {

	char *file="plist1.plist";
	printf("Loading: %s\n",file);
	Dictionary dict=PList_Load(file,0);
	if (!dict) quit("Error loading file(%s): %s\n",file,OError());

	if (!isa_(dict,Dictionary)) quit("Bad format");

	if (!isa_( Dict_sub(dict,"Colors"),   Array))      quit("[Colors] is not an Array");
	if (!isa_( Dict_sub(dict,"Number"),   Huge))       quit("[Number] is not a Huge");
	if (!isa_( Dict_sub(dict,"Rate"),     Real))       quit("[Rate] is not a Real");
	if (!isa_( Dict_sub(dict,"Flag"),     Bool))       quit("[Flag] is not a Bool");
	if (!isa_( Dict_sub(dict,"Raw data"), Data))       quit("[Raw data] is not a Data");
	if (!isa_( Dict_sub(dict,"Date"),     DateString)) quit("[Date] is not a DateString");
	if (!isa_( Dict_sub(dict,"SubDict"),  Dictionary)) quit("[SubDict] is not a Dictionary");

	printf("finish testing\n");

	return(0);
	}

static void __attribute__((constructor)) boot() { register_demo(code,desc,demo3); }

