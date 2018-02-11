pattern = "good";
alphabet = "abcdefghijklmnopqrstuvwxyz"

[-1, -1, ..., 3, ... 0, ..., 2, ...] 128



int *lastOccurrence(char *pattern, char *alphabet) {
    int alphabetLength = strlen(alphabet);
    int patternLength = strlen(pattern);
    int i;
    int *lastOccurenceList = malloc(sizeof(int) * 128);
    assert(lastOccurenceList != NULL);

    for (i = 0; i < alphabetLength; i++) {
        lastOccurenceList[i] = -1;
    }

    for (i = 0; i < patternLength; i++) {
        lastOccurenceList[(int)pattern[i]] = i;
    }

    return lastOccurenceList;
}