	#include "coda-c_plist.h"
	#include "coda-c_strings.h"

	#include <assert.h>

	void register_demo(char *code,char *name,pointer demofun);

	#define quit(cs,...) printf("*ERROR*  " cs "\n",##__VA_ARGS__),exit(1)

