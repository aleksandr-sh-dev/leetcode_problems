int mySqrt(int x)
{
    long long int begin, answer = 0;
    long long int end = x;
    long long int mid;

    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        
        if (mid * mid == x) {
            return mid;
        }
        else if (mid * mid < x) {
            answer = mid;
            printf("\nAnswer in cycle: %d", answer);
            begin = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return answer;
}
