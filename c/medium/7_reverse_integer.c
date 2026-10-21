int reverse(int x) {
    int reversed_x = 0;
    
    while (x != 0) {
        int remainder = x % 10;
        x /= 10;
        
        // Check for positive overflow
        if ((reversed_x > INT_MAX / 10) || ((reversed_x == INT_MAX / 10) && (remainder > 7))) {
            return 0;
        }
        
        // Check for negative underflow
        if ((reversed_x < (INT_MIN / 10)) || ((reversed_x == (INT_MIN / 10)) && (remainder < -8))) {
            return 0;
        }
        
        // Construct the reversed num
        reversed_x = (reversed_x * 10) + remainder;
    }
    
    return reversed_x;
}