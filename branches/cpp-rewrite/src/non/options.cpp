#include "options.h"
#include "optionexception.h"

void non::Options::add(string str, unsigned argcount, int id) {
    option opt;

    opt.argcount = argcount;
    opt.id = id;
    opt.str = str;

    options.insert(options.end(), opt);
}

void non::Options::parse(int argc, char **argv) {
    unsigned i, it_arg;
    list<option>::iterator it_opt;

    args.clear();

    for(i = 1; static_cast<int>(i) < argc; i++) {
        for(it_opt = options.begin(); it_opt != options.end(); it_opt++) {
            if((*it_opt).str == argv[i]) {
                list<string> optargs;

                for(it_arg = i + 1; it_arg - i - 1 < (*it_opt).argcount && static_cast<int>(it_arg) < argc; it_arg++)
                    optargs.insert(optargs.end(), string(argv[it_arg]));

                if(optargs.size() != (*it_opt).argcount)
                    throw OptionException("Not enough arguments for option " + (*it_opt).str);

                args.insert(args.end(), arg((*it_opt).str, optargs, (*it_opt).id, true));
                i += (*it_opt).argcount;
                break;
            }
        }

        if(it_opt == options.end())
            args.insert(args.end(), arg(argv[i], list<string>(), -1, false));
    }
}
