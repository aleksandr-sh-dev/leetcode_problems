int calPoints(char** operations, int operationsSize) {
    int nums[1000] = {0}; // O(n) space
    int j = 0; // pointer for nums;
    int val = 0;

    for (int i = 0; i < operationsSize; i++) {
        if (operations[i][0] == '+') {
            nums[j] = nums[j - 1] + nums[j - 2];
        } else if (operations[i][0] == 'D') {
            nums[j] = nums[j - 1] * 2;
        } else if (operations[i][0] == 'C') {
            j--;
            continue;
        } else {
            val = atoi(operations[i]);
            nums[j] = val;
        }

        j++;
    }

    int res = 0;

    for (int k = 0; k < j; k++) {
        res += nums[k];
    }

    return res;
}