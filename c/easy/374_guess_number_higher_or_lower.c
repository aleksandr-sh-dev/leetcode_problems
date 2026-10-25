/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

int guessNumber(int n) {
    // If only one n immediately return it
    if (n == 1) {
        return n;
    }

    // Check if guessed number is n itself
    if (guess(n) == 0) {
        return n;
    }

    // Otherwise start binary search
    unsigned long left = 1; // Task says that number starts from 1, not 0
    unsigned long right = n; // Right border is n
    unsigned long long middle = 0;

    while (left <= right) {
        middle = (left + right) / 2;
        int res = guess(middle);
        if (res == 0) {
            return middle;
        } else if (res == 1) {
            left = middle + 1; // We skip middle because it've been checked already
        } else if (res == -1) {
            right = middle -1; // We skip middle because it've been checked already
        }
    }

    return 0;
}
