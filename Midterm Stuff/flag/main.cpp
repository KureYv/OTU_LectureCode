#include "casemagic.h"
#include "uppercase.h"
#include "lowercase.h"
#include "capitalcase.h"

int main() {
    // making a base class pointer
    CaseMagic* wand;
    int flag;
    cin >> flag;
    // todo: grab the flag from the user; more code is needed here
    switch (flag) {
        // setting the pointer to a subclass
        case "-u":
            wand = new UpperCase();
            break;
        case "-l":
            wand = new LowerCase();
            break;
        case "-c":
            wand = new CapitalCase();
            break;
    }

    // going into the main loop
    string line;
    do
    {
        // grabbing user input
        cout << "$ ";
        getline(cin, line);
        // breaking if 'q'
        if (line.length() == 1 && line == "q") { break; }
        cout << wand->transmogrify(line) << endl;
    } while(true);
    delete wand;
    return 0;
}