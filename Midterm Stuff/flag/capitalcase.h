// capitalcase.h
#include "casemagic.h"
class CapitalCase : public CaseMagic {
    public:
        string transmogrify(string str) override{
            string rs;
            bool newWord;
            for(int i=0;i<str.length();i++){
                if(i==0 || newWord ){
                    rs+=toupper(str[i]);
                    newWord = false;
                }
                else{
                    rs+=str[i];
                }
                if(str[i] == ' '){
                    newWord = true;
                }
            }
            return rs;
        };
};