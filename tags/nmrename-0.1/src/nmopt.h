struct nmopts {
	int id;
	char *option;
	int argcount;
	char *text;
};

struct nmopts *nmopt(char **argv, int argc, struct nmopts *options, int *index);
