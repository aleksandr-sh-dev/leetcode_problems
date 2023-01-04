#define ROMAN_SYMBOLS_COUNT    13u

typedef struct {
    int integer_num;
    char *roman_symbol;
} roman_num;

char *intToRoman(int num)
{
    char *result = (char *)malloc(sizeof(char) * 50);
    result[0] = '\0';
    
    roman_num roman_num_arr[ROMAN_SYMBOLS_COUNT] = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
	
	int ratio = 0;	
		
    if (num < 1 || num > 3999) {
        return 0;
    }
    
    if (num == 0) {
        return 0;
    }

    for (int i = ROMAN_SYMBOLS_COUNT - 1; i >= 0; i--) {
        ratio = num / roman_num_arr[i].integer_num;
        while (ratio > 0) {
            strcat(result, roman_num_arr[i].roman_symbol);
            ratio--;
        }
        num = num % roman_num_arr[i].integer_num;
    }
    
    return result;
}
