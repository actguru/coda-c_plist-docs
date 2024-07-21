	#include "demo.h"

static Dictionary codes=0;
static Dictionary names=0;

void register_demo(char *code,char *name,pointer demofun) {
	if (!codes) codes=newO(Dictionary);
	if (!names) names=newO(Dictionary);
	if (!code) return;
	Dict_set(codes,code,Pointer_Value(demofun));
	Dict_set(names,code,name);
	}

static void listdemos() {
	printf("\n");
	printf("List of demos\n");
	printf("-------------------------------------------------------\n");
	Pointer list=Dictionary_AllKeys(codes);
	pointer_sort(list,Pointer_count(list),strcmp,0);
	for(int j=0;j<Pointer_count(list);++j) {
		char *code=list[j];
		char *name=Dict_sub(names,code);
		printf("%s - %s\n",code,name);
		}
	printf("\n");
	printf("demo: code | [default list] | -all\n");
	}

int rundemo(char *code,int argc,char **argv) {
	char *name=Dict_sub(names,code);
	Pointer ptr=Dict_sub(codes,code);
	if (!ptr) quit("Can't locate test(%s) please use upper case...",code);
	int (*demofun)(int,char **)=ptr[0]; assert(demofun);

	printf("\n");
	printf("Demo: %s  %s\n",code,name);
	printf("-------------------------------------------------------\n");

	return demofun(argc,argv);
	}

void runall(int argc,char **argv) {
	Pointer list=Dictionary_AllKeys(codes);
	pointer_sort(list,Pointer_count(list),strcmp,0);
	for(int j=0;j<Pointer_count(list);++j) {
		char *code=list[j];
		rundemo(code,argc,argv);
		}
	}

int main(int argc,char **argv) {
	register_demo(0,0,0);
	if (argc<2) { listdemos(); return(0); }
	if (cs_exact("-all",argv[1])) runall(argc,argv);
	  else rundemo(argv[1],argc-1,argv+1);
	}

