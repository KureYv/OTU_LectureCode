// uppercase.h
#include "casemagic.h"
class UpperCase : public CaseMagic {
    public:
        string transmogrify(string str) override{
            string rs;
            for(int i=0;i<str.length();i++){
                rs+=toupper(str[i]);
            }
            return rs;
        };
};