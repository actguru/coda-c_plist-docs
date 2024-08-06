	#include "demo.h"

static char code[]="4",desc[]="Display Dictionary values.";

int demo4() {

	char *file="plist1.plist";
	printf("Loading: %s\n",file);
	Dictionary dict=Json_Load(file,0);
	if (!dict) quit("Error loading file(%s): %s\n",file,OError());

	for(Keyword key=Dictionary_scan(dict);key;key=Dictionary_next(key)) {
		char *word=key->word;
		Obj obj=key->item;
		if (isa_(obj,Huge)) {
			Huge hhh=obj;
			printf("%s = %lld\n",word,*hhh);
			}
		else if (isa_(obj,Real)) {
			Real rrr=obj;
			printf("%s = %4.3f\n",word,*rrr);
			}
		else if (isa_(obj,Bool)) {
			Bool bbb=obj;
			printf("%s = %d\n",word,*bbb);
			}
		else if (isa_(obj,Char)) { // DateString, ConstChar alos...
			Char ccc=obj;
			printf("%s = '%s'\n",word,ccc);
			}
		else if (isa_(obj,Data)) {
			Data ddd=obj;
			printf("%s = %d bytes of <RAW DATA>\n",word,sizeO(ddd));
			}
		else if (isa_(obj,Array)) {
			printf("%s = Array with %d items\n",word,Array_count(obj));
			}
		else if (isa_(obj,Dictionary)) {
			printf("%s = Dictionary with %d items\n",word,Dictionary_count(obj));
			}
		else {
			printf("%s = *** UNKNOWN OBJECT with class(%s) ***\n",word,kindO(obj));
			}
		}

	printf("finish testing\n");

	return(0);
	}

static void __attribute__((constructor)) boot() { register_demo(code,desc,demo4); }

