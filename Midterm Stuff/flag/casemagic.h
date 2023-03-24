// casemagic.h
#include <iostream>
#include <string>
#pragma once
using namespace std;
class CaseMagic {
    public:
        CaseMagic() {};
        virtual ~CaseMagic() {};
        virtual string transmogrify(string) = 0;
};
