#include <array>

unsigned int cellNameToIdx(const char *name) {
    char letter = name[0];
    char digit = name[1];

    return (digit - '1') * 8 + (letter - 'a');
}

std::array<char, 2> cellIdxToName(const unsigned int idx) {
    char digit = '1' + idx / 8, letter = 'A' + idx % 8;
    return std::array<char, 2>({digit, letter});
}