#ifndef L1V2CL_STACKELEMENTPARENT_H
#define L1V2CL_STACKELEMENTPARENT_H

#include <istream>
#include <ostream>

class StackElementParent {
public:
    virtual std::string save () {};
    virtual void load (std::istream &s) {};
    virtual std::string print () {};
    std::string whoami() {
        return className;
    }

protected:
    std::string className = "StackElementParent";
};

#endif //L1V2CL_STACKELEMENTPARENT_H

