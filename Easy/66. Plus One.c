#define DIGITS_MAX_LENGTH    100u
#define DIGITS_MAX_NUM       9u

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int *result = (int*)malloc(sizeof(int) * DIGITS_MAX_LENGTH);
    int increment = 1;

    for (int i = digitsSize - 1; i >= 0; i--) {
        if ((digits[i] + increment) > DIGITS_MAX_NUM) {
            digits[i] = (digits[i] + increment) % 10;
        }
        else {
            digits[i] = digits[i] + increment;
            increment = 0;
            break;
        }
    }

    if (increment != 0) {
        result[0] = 1;
    }

    for (int i = increment, j = 0; j < digitsSize; j++, i++) {
        result[i] = digits[j];
    }

    *returnSize = digitsSize + increment;

    return result;
}
