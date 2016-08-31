
#include <iostream>
#include <algorithm>
#include <map>

#include "main-better.h"

using namespace std;


int main() {
    string s1 = "asd";
    string s2 = "This clearly does not.";

    EvalInput(s1);
    EvalInput(s2);

    return 0;
}

bool HasOnlyUnique(string s) {
    std::map<char, int> m;

    for (std::string::iterator c = s.begin(); c != s.end(); ++c) {
        if (m.find(*c) == m.end()) {
            m[*c] = 0;
        } else {
            return false;
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
