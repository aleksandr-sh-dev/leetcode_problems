char result[201];

char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];

    int j = 0;
    char prefix = strs[0][j];
    
    while (prefix != '\0') {
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][j] == '\0') {
                result[j] = '\0';
                return result;
            }
            else if (strs[i][j] != prefix) {
                    result[j] = '\0';
                    return result;
                }
            }
        result[j] = prefix;
        j++;
        prefix = strs[0][j];
    }

    result[j] = '\0';
    return result;
}