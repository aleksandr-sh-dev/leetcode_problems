int romanToInt(char *s) 
{
    char *s_ptr = s;
    int num = 0;

    for (;*s_ptr != '\0'; s_ptr++) {
        switch (*s_ptr) {
            case 'I':
                switch (*(s_ptr + 1)) {
                    case 'I':
                        num += 1;
                        break;
                    case 'V':
                        num += 4;
                        s_ptr++;
                        break;
                    case 'X':
                        num += 9;
                        s_ptr++;
                        break;
                    default:
                        num += 1;
                        break;
                }
                break;
            case 'V':
                num += 5;
                break;
            case 'X':
                switch (*(s_ptr + 1)) {
                    case 'L':
                        num += 40;
                        s_ptr++;
                        break;
                    case 'C':
                        num += 90;
                        s_ptr++;
                        break;
                    case 'X':
                        num += 10;
                        break;
                    default:
                        num += 10;
                        break;
                }
                break;
            case 'L':
                num += 50;
                break;
            case 'C': 
                switch(*(s_ptr + 1)) {
                    case 'D':
                        num += 400;
                        s_ptr++;
                        break;
                    case 'M':
                        num += 900;
                        s_ptr++;
                        break;
                    case 'C':
                        num += 100;
                        break;
                    default:
                        num += 100;
                        break;
            }
                break;
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;
        }
    }

    return num;
}
