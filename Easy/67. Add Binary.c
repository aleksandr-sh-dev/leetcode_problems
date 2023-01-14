#define ASCII_0               48u
#define CHECK_FOR_CARRY(x)    ((x) /=(2))

char *addBinary(char *a, char *b)
{
    int sum = 0;
    int str_a = strlen(a);
    int str_b = strlen(b);

    int longest_string = (str_a > str_b ? str_a : str_b) + 1;

    char *c = (char*)malloc(longest_string + 1);

    c[longest_string] = NULL;
    
    while (str_a > 0 || str_b > 0 || sum > 0) {
        if (str_a > 0) {
            sum += a[--str_a] - ASCII_0;
        }
        if (str_b > 0) {
            sum += b[--str_b] - ASCII_0;
        }

        c[--longest_string] = sum % 2 + ASCII_0;
        CHECK_FOR_CARRY(sum);
    }

    return (c + longest_string);
}
