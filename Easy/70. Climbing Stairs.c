int climbStairs(int n)
{
    int fibonacci, x = 0;
    int y = 1;

    for (int i = 0; i < n; i++) {
        fibonacci = y + x;
        x = y;
        y = fibonacci;
    }

    return fibonacci;
}
