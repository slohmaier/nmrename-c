#include "nmopt.h"
#include "msg.h"
#include "string.h"

struct nmopts *nmopt(char **argv, int argc, struct nmopts *options, int *index) {
	struct nmopts *result = options;
	*index=*index+1;
	
	//exit if at end
	if(*index >= argc) return NULL;
	
	for(; result->option != NULL; ++result) {
		if(strcmp(argv[*index], result->option) == 0)
			return result;
	}
	
	//So no match was found? return the error structure.
	return(result);
}
