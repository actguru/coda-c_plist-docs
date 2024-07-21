// Stephen M. Jones // 07/20/2024

// Example program to: "Print lines from <stdin> in sorted order."

	#include "coda-c_plist.h"
	#include "coda-c_strings.h"

int main() {

	cleanO Array list=newO(Array);
	char aa[1024];
	while(EOF!=file_getCs(stdin,aa,sizeof(aa))) {
		Array_take(list,Char_Value(aa));
		}

	pointer_sort(Array_rawAddress(list),Array_count(list),strcmp,0);

	for(int j=0;1;++j) {
		Char str=Array_subInt(list,j); if (!str) break;
		printf("%s\n",str);
		}
	}

