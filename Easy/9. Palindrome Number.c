bool isPalindrome(int x){
    int num = x;
    long int reverse = 0;

    while (num){
        int last_num = num % 10;

        reverse = reverse * 10 + last_num;

        num = num / 10;
    }

    if (x == reverse && x >= 0) {
        return true;
    }

    return false;
}
