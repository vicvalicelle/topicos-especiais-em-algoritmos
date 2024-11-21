// beecrowd 2667 - Mouth Game

#include <iostream>
#include <string>
using namespace std;

int main() {
    string N;
    cin >> N;  // Read the large number N as a string

    // Calculate N mod 3.
    int mod = 0;
    for (char digit : N) {
        mod = (mod * 10 + (digit - '0')) % 3;  // Update the remainder when divided by 3
    }

    // If N mod 3 is 0, the first player cannot win.
    // If N mod 3 is 1, the first player can win by choosing 1.
    // If N mod 3 is 2, the first player can win by choosing 2.
    if (mod == 0) {
        cout << 0 << endl;  // The first player cannot win, so output 0
    } else {
        cout << mod << endl;  // Output 1 or 2 depending on the remainder
    }

    return 0;
}
