void nm_delete(char* *pathlist, int pathno, char* cpos1, char* cpos2);
void nm_replace_str(char **pathlist, int pathno, char *str1, char* str2);
void nm_delete_str(char **pathlist, int pathno, char *str);
void nm_insert_str(char **pathlist, int pathno, char *str, char* cpos);
void nm_camel_case_str(char **pathlist, int pathno);
void nm_upper_case_str(char **pathlist, int pathno);
void nm_lower_case_str(char **pathlist, int pathno);
void nm_delete_field(char **pathlist, int pathno, char *cnum, char *dels);
