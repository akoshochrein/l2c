
#include "solution.h"

bool IsOneAway(std::string input, std::string from) {
    int errors = 0;
    int inputLength = input.length();
    int fromLength = from.length();

    bool inputIsLonger = inputLength > fromLength;
    bool fromIsLonger = inputLength < fromLength;

    std::string::iterator inputIterator = input.begin();
    std::string::iterator fromIterator = from.begin();

    if (inputLength > fromLength + 1 || fromLength > inputLength + 1) return false;

    while (inputIterator != input.end() && fromIterator != from.end()) {
        if (*inputIterator != *fromIterator) {
            errors += 1;
            if (inputIsLonger) {
                inputIterator += 1;
                if (inputIterator != input.end() && *inputIterator != *fromIterator)
                    errors += 1;
            }
            if (fromIsLonger) {
                fromIterator += 1;
                if (fromIterator != from.end() && *inputIterator != *fromIterator)
                    errors += 1;
            }
            if (errors > 1) return false;
        }
        inputIterator += 1;
        fromIterator += 1;
    }

    return true;
}
