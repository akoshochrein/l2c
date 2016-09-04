
#include <cctype>
#include <map>
#include <iostream>
#include "solution.h"

bool IsPalindromePermutation(std::string s) {
    std::map<char, int> m;

    for (std::string::iterator c = s.begin(); c != s.end(); ++c) {
        *c = tolower(*c);
        if (*c != ' ') {
            if (m.find(*c) == m.end()) {
                m[*c] = 1;
            } else {
                m[*c] += 1;
            }
        }
    }

    int odds = 0;
    for (std::map<char, int>::iterator k = m.begin(); k != m.end(); ++k) {
        if (k->second % 2 != 0) {
            odds += 1;
            if (odds > 1) return false;
        }
    }

    return true;
}
