#include "helper.cpp"

/**
 * Determines the number of bits that need to be flipped in order to convert
 * a to b.
 */
int bit_swap_required(int a, int b)
{
    int count = 0;
    /* c & (c -1) clears the least significant bit.
     * In this loop, it essentially counts the numbers of 1s. */
    for (int c = a ^ b; c; c = c & (c - 1))
        count++;
    return count;
}

int main()
{
    cout << bit_swap_required(0b11101, 0b01111) << endl;     // 2
    cout << bit_swap_required(0b1000001, 0b1111111) << endl; // 5

    return 0;
}