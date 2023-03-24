// lowercase.h
#include "casemagic.h"
class LowerCase : public CaseMagic {
    public:
        string transmogrify(string str) override{
            string rs;
            for(int i=0;i<str.length();i++){
                rs+=tolower(str[i]);
            }
            return rs;
        }
};