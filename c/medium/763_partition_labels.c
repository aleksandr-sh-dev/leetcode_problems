/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* s, int* returnSize) {
    int* result = (int*)malloc(500 * sizeof(int)); // Allocate 2 Kb because max len could be 500
    int letter_last_pos[26] = {0}; // There are 26 lowercase English letters
    int len = strlen(s);
    
    // Collect positions of all letters end indexes
    for (int i = 0; i < len; i++) {
        letter_last_pos[s[i] - 'a'] = i;
    }

    int max_last_pos = 0;
    int left = 0;
    int right = 0;
    int str_num = 0;

    while (right < len) {
        max_last_pos = (max_last_pos > (letter_last_pos[s[right] - 'a']) ? 
                                            max_last_pos : (letter_last_pos[s[right] - 'a']));
        if (right == max_last_pos) {
            result[str_num] = max_last_pos - left + 1;
            max_last_pos = 0;
            str_num++;
            left = right + 1;
        }

        right++;
    }

    *returnSize = str_num;

    return result;
}
