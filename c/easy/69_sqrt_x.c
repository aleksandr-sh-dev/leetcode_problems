int mySqrt(int x) {
    if (x == 0) {
        return 0;
    }

    if (x > 0 && x < 4) {
        return 1;
    }

    int left = 1;
    int right = x;
    int middle = 0;
    int answer = 0;

    while (left <= right) {
        middle = left + (right - left) / 2;
        
        int num = x / middle;

        if (num == x / num) {
            answer = middle;
            break;
        }

        if (middle > num) {
            right = middle - 1;
        } else {
            answer = middle;
            left = middle + 1;
        }
    }

    return answer;
}