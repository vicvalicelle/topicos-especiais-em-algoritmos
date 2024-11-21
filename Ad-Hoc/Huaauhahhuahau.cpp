// beecrowd 2242 - Huaauhahhuahau

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string laugh;  // Variable to hold the input laugh sequence

    cin >> laugh;  // Read the input laugh sequence

    vector<char> laugh_vector(laugh.begin(), laugh.end());  // Convert the laugh string to a vector of characters
    vector<char> vowels;  // Vector to store the vowels in the laugh sequence
    vector<char> reversed_vowels;  // Vector to store the vowels in reverse order

    // Loop through each character in the laugh sequence
    for (int i = 0; i < laugh_vector.size(); i++) {
        // Check if the current character is a vowel
        if (laugh_vector[i] == 'a' || laugh_vector[i] == 'e' || laugh_vector[i] == 'i' || laugh_vector[i] == 'o' || laugh_vector[i] == 'u') {
            vowels.push_back(laugh_vector[i]);  // Add the vowel to the vowels vector
            reversed_vowels.push_back(laugh_vector[i]);  // Also add it to the reversed vowels vector
        }
    }

    reverse(reversed_vowels.begin(), reversed_vowels.end());  // Reverse the reversed_vowels vector

    // Compare the vowels vector with the reversed vowels vector
    if(vowels == reversed_vowels) {
        cout << "S" << endl;  // Output "S" if the laugh sequence is funny (vowels are the same forwards and backwards)
    }
    else {
        cout << "N" << endl;  // Output "N" if the laugh sequence is not funny (vowels are not the same forwards and backwards)
    }

    return 0;  // End of the program
}
