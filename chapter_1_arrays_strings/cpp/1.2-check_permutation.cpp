#include <iostream>
#include <string>

using namespace std;

// O(n) solution
bool check_permutation(string str1, string str2)
{
    const int ASCII_LENGTH = 128;
    int map[ASCII_LENGTH] = {0};

    if (str1.length() != str2.length())
        return false;
    for (auto ch : str1)
        map[ch] += 1;
    for (auto ch : str2)
    {
        map[ch]--;
        if (map[ch] < 0)
            return false;
    }
    return true;
}

int main()
{
    cout << check_permutation("dog", "god") << endl;     // 1
    cout << check_permutation("dog", "God") << endl;     // 0
    cout << check_permutation("dog", "good") << endl;    // 0
    cout << check_permutation("mmmmm", "mmmmm") << endl; // 1
    cout << check_permutation("mmmmm", "mmmmn") << endl; // 0

    return 0;
}