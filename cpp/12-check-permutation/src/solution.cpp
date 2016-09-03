#include "solution.h"
#include <iostream>
#include <map>
using namespace std;


bool ArePermutations(std::string s1, std::string s2) {
    if (s1.length() != s2.length()) return false;

    std::map<char, int> m;
    for (std::string::iterator c = s1.begin(); c != s1.end(); ++c) {
        if (m.find(*c) == m.end()) {
            m[*c] = 1;
        } else {
            m[*c] += 1;
        }
    }

    for (std::string::iterator c =s2.begin(); c != s2.end(); ++c) {
        if (m.find(*c) == m.end()) return false;
        else {
            m[*c] -= 1;
            if (m[*c] == 0) {
                m.erase(*c);
            }
        }
    }

    if (!m.empty()) return false;

    return true;
}
