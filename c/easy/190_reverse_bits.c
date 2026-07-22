int reverseBits(int n) {
    int num_bits = sizeof(int) * 8;
    unsigned int reverse = 0;
    unsigned int un = (unsigned int)n;

    for (int i = 0; i < num_bits; i++) {
        if (un & (1u << i)) {
            reverse |= 1u << (num_bits - i - 1);
        }
    }

    return reverse;
}
