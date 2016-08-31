
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

bool HasOnlyUnique(string s);
void EvalInput(string s);

int main() {
    string s1 = "asd";
    string s2 = "This clearly does not.";

    EvalInput(s1);
    EvalInput(s2);

    return 0;
}

bool HasOnlyUnique(string s) {
    std::list<char> l;

    for (std::string::iterator c = s.begin(); c != s.end(); ++c) {
        int numChars = std::count(l.begin(), l.end(), *c);
        if (numChars != 0) {
            return false;
        } else {
            l.push_back(*c);
        }
    }

    return true;
}

void EvalInput(string s) {
    if (HasOnlyUnique(s)) {
        cout << "String \""<< s << "\" only has unique characters in it." << endl;
    } else {
        cout << "String \""<< s << "\" has non-unique characters in it." << endl;
    }
}
