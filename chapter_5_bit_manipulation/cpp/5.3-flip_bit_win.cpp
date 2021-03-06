#include <iostream>

using namespace std;

/**
 * Calculates number of consecutive 1s if user if able to flip 1 bit to 1.
 */
int flip_bits(int n)
{
    int max_len, curr_len, prev_len;
    if (~n == 0)
        return sizeof(int) * 8;

    max_len = curr_len = prev_len = 0;
    while (n)
    {
        if (n & 1)
            curr_len++;
        else
        {
            /* Update to 0 (if next bit is 0) or curr_len. */
            prev_len = n & 2 ? curr_len : 0;
            curr_len = 0;
        }
        max_len = max(curr_len + prev_len + 1, max_len);
        n >>= 1;
    }
    return max_len;
}

int main()
{
    cout << flip_bits(0b11011101111) << endl; // 8
    cout << flip_bits(0b11111101111) << endl; // 11
    cout << flip_bits(0b10101010101) << endl; // 3

    return 0;
}