unsigned int cellNameToIdx(const char *name) {
    char letter = name[0];
    char digit = name[1];

    return (digit - '1') * 8 + (letter - 'a');
}