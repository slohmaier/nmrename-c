#include <iostream>
#include "non/options.h"
#include "non/path.h"
#include "renamer.h"
using non::Path;
using namespace std;

void print_help();

int main(int argc, char **argv) {
    non::Options opts;
    list<non::Options::arg>::iterator it;
    list<string> paths, newpaths;
    list<string>::iterator itso, itsn;

    opts.add("-h", 0, OPT_HELP);
    opts.add("-sd", 1, OPT_STRDEL);

    opts.parse(argc, argv);

    for(it = opts.begin(); it != opts.end(); it++) {
        if(it->isArg()) {
            switch(it->getId()) {
                case OPT_HELP: print_help(); return 0;

                default:
                    newpaths = renamer(paths, it->getId(), it->getArgs());

                    for(itsn = newpaths.begin(), itso = paths.begin(); itsn != newpaths.end(); itso++, itsn++)
                        if(*itso != *itsn)
                            cout << *itso << " >> " << *itsn << endl;

                    paths = newpaths;
            }
        }
        else {
            if(Path::isFile(it->getStr()))
                paths.insert(paths.end(), it->getStr());
            else {
                cerr << "\"" << it->getStr() << "\" is not a valid file for renaming. Aborting..." << endl;
                return 1;
            }
        }
    }

    return 0;
}

void print_help() {
    cout << "\n"
        << "nmrename %s - A mass renaming tool.\n"
        << "Copyright 2007-2009 by Stefan Lohmaier\n"
        << "\n"
        << "Usage:\n"
        << "    nmrename [PATHLIST] [COMMANDS]\n"
        << "\n"
        << "  [PATHLIST] is a list of the paths (dirs and files) you want to rename.\n"
        << "  [COMMANDS] is a list of commands that will be executed one by one.\n"
        << "\n"
        << "COMMANDS:\n"
        << "  -h    : Print this text.\n"
        << "  -f    : Renames without asking. Use with CAUTION!\n"
        << "  -c    : Clear the pathlist.\n"
        << "\n"
        << "  -cc   : Camelcase (e.g. hallo -> Hallo)\n"
        << "  -cu   : Uppercase (e.g. hallo -> HALLO)\n"
        << "  -cl   : Lowercase (e.g. HALLO -> hallo)\n"
        << "\n"
        << "  -d [POS1] [POS2] : Remove from POS1 to POS2.\n"
        << "\n"
        << "  -sr [S1] [S2]    : Replace all occurences of S1 with S2.\n"
        << "  -sd [S]          : Delete all occurences of S.\n"
        << "  -si [S] [POS]    : Insert S at POS.\n"
        << "\n"
        << "  -fd [POS] [S]         : Deletes field POS. Fielddelimiters are in S.\n"
        << "  -fs [POS1] [POS2] [S] : Switches field POS1 with field POS2.\n"
        << "                          Fielddelimiters are in S.\n"
        << "\n"
        << "  -l [FILENAME] : Loads new pathnames from [FILENAME] (List MUST have\n"
        << "                  EXACTLY as many paths as paths in the pathlist!)\n"
        << "\n"
        << "  -exif [PATTERN] : New Pathnames will be replaced by PATTERN.\n"
        << "\n"
        << "        PATTERN can have the following keywords:\n"
        << "          Date:\n"
        << "            %Y: year\n"
        << "            %M: month\n"
        << "            %D: day\n"
        << "            %h: hour\n"
        << "            %m: minute\n"
        << "            %s: second\n"
        << "\n"
        << "          Other:\n"
        << "            %o: original filename\n"
        << "\n"
        << "  [POS*] can be 0,1,2,... or -0,-1,-2,... ('-' starts counting from the right).\n"
        << "  [S*] is a string of your choice.\n"
        << "\n";
}
