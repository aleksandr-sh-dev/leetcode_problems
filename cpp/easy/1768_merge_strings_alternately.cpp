#include <string>

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = {0};
        result.clear();
        int i = 0;
        int j = 0;

        while (word1[i] != '\0' || word2[j] != '\0') {
            if (word1[i] != '\0') {
                result.push_back(word1[i]);
                i++;
            }

            if (word2[j] != '\0') {
                result.push_back(word2[j]);
                j++;
            }
        }

        return result;
    }
};