// Stephen M. Jones // 08/05/2024

// Example program to: "Report the number of times each word from <stdin> is used."

	#include "coda-c_plist.h"
	#include "coda-c_strings.h"

static Char get_Word(FILE *is) {
	char buf[128]; int pos=0;
	while(1) {
		int cc=cc_toLow(fgetc(is)); if (cc==EOF) break;
		if (cc>='a' && cc<='z') { buf[pos++]=cc; if (pos>=100) break; }
		else if (pos) break;
		}
	buf[pos]=0; return (pos ? Char_Value(buf) : 0);
	}

int main() {
  Object_Leaks(); {
	defer_call(puts,"<<End of word counting>>");
	cleanO Dictionary dict=newO(Dictionary);
	while(1) {
		cleanO Char word=get_Word(stdin); if (!word) break;
		Huge count=Dictionary_subKey(dict,word);
		if (!count) Dictionary_takeKey(dict,word,Huge_Value(1)); else ++(*count);
		}
	for(Keyword key=Dictionary_scan(dict);key;key=Dictionary_next(key)) {
		Huge count=key->item;
		printf("%s=%lld\n",key->word,*count);
		}
	char *ofile="words.json";
	printf("Saving: %s\n",ofile);
	if (!Json_save(ofile,dict,PLIST_Json|JSON_Pretty|JSON_NoEscapeSlash))
		printf(">> Error: %s\n",OError());
  	}
  }

