int lengthOfLongestSubstring(char *s)
{
    int counter = 0;
    char index[255] = {0};

    for (int i = 0; i < strlen(s); i++) {
        int pre_counter = 1;
        memset(index, NULL, sizeof(index));
        index[s[i]] = s[i];
        for (int j = (i + 1); j < strlen(s); j++) {
            if (index[s[j]] != NULL) {
                break;
            }
            index[s[j]] = s[j];
            pre_counter++;
        }

        if (pre_counter > counter) {
            counter = pre_counter;
        }
    }

    return counter;
}
