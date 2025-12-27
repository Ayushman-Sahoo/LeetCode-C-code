#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;

    // Take two words from user
    cout << "Enter first word: ";
    cin >> str1;

    cout << "Enter second word: ";
    cin >> str2;

    // If lengths are different, not an anagram
    if (str1.length() != str2.length()) {
        cout << "Not an anagram" << endl;
        return 0;
    }

    // Create two arrays to count characters (for a-z)
    int count1[26] = {0};
    int count2[26] = {0};

    // Count letters in both strings
    for (int i = 0; i < str1.length(); i++) {
        count1[str1[i] - 'a']++;
        count2[str2[i] - 'a']++;
    }

    // Compare both counts
    bool isAnagram = true;
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            isAnagram = false;
            break;
        }
    }

    // Show result
    if (isAnagram)
        cout << "It is a valid anagram!" << endl;
    else
        cout << "Not an anagram" << endl;

    return 0;
}