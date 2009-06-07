#ifndef RENAMER_H
#define RENAMER_H

#include <string>
#include <list>

using std::string;
using std::list;

#define OPT_HELP 0
#define OPT_STRDEL 1

list<string> renamer(list<string>, int opt, list<string>);

#endif // RENAMER_H
