char **nm_delete(char* *pathlist, int pathno, char* cpos1, char* cpos2);
char **nm_replace_str(char **pathlist, int pathno, char *str1, char* str2);
char **nm_delete_str(char **pathlist, int pathno, char *str);
char **nm_insert_str(char **pathlist, int pathno, char *str, char* cpos);
char **nm_camel_case_str(char **pathlist, int pathno);
char **nm_upper_case_str(char **pathlist, int pathno);
char **nm_lower_case_str(char **pathlist, int pathno);
char **nm_delete_field(char **pathlist, int pathno, char *cnum, char *dels);
