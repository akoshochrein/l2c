
#include <sstream>
#include <string>
#include "solution.h"

std::string Compress(std::string s) {
    std::ostringstream compressed;
    int counter = 0;
    char prevChar = *s.begin();

    for (std::string::iterator c = s.begin(); c != s.end(); ++c) {
        if (prevChar != *c && counter != 0) {
            compressed << prevChar << std::to_string(counter);
            prevChar = *c;
            counter = 1;
        } else if (prevChar == *c) {
            counter += 1;
        }
    }
    compressed << prevChar << std::to_string(counter);

    std::string compressedString = compressed.str();

    return
        s.length() > compressedString.length()
            ? compressedString
            : s;
}
