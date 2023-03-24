#include <iostream>
#include <string>

using namespace std;

class Tag {
    public:
        string base;
    
    // class constructor
        Tag(string tag) : base(tag) {}
        

    // add doc string
        string wrap(string text) {
            return "<" + this->base + ">" + text + "</" + this->base + ">";
        }

    // add doc string
        string wrapnl(string text) {
            return "<" + this->base + ">\n" + text + "\n</" + this->base + ">";
        }
};

int main() {

    // making some tags
    Tag html = Tag("html");
    Tag body = Tag("body");
    Tag h1 = Tag("h1");
    Tag p = Tag("p");

    // creating the document
    string doc = html.wrapnl(
        body.wrapnl(
            h1.wrap("Hello world!") + "\n" +
            p.wrap("This came from a C++ program")
        )
    );
    cout << doc << endl;

    return 0;
}