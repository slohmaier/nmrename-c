#ifndef NON_OPTIONS_H
#define NON_OPTIONS_H

#include <string>
#include <list>

using std::string;
using std::list;

namespace non {

class Options
{
private:
    typedef struct {
        string str;
        unsigned argcount;
        int id;
    } option;

    /** Class for arguments */
    class arg {
        public:
            arg(string s, list<string> args, int id=-1, bool isarg=true) :
                    str(s), args(args), id(id), isarg(isarg) {}

            inline string getStr() {return str;}
            inline list<string> getArgs() {return args;}
            inline int getId() {return id;}
            inline bool isArg() {return isarg;}

        private:
            const string str;
            const list<string> args;
            const int id;
            const bool isarg;
    };

    list<arg> args;
    list<option> options;

public:
    void add(string str, unsigned argcount=0, int id=-1);
    void parse(int argc, char **argv);
    inline list<arg>::iterator begin() {return args.begin();}
    inline list<arg>::iterator end() {return args.end();}
};

}

#endif // NON_OPTIONS_H
