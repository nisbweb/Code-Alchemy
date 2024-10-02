/*
    Valid Anagram
    Given two strings s and t, write a function to determine if t is an anagram of s.

    Input:
    Two strings s and t.
    Output:
    Return true if t is an anagram of s, otherwise return false.

    Example:
    Input:
    s = "anagram", t = "nagaram"
    
    Output:
    true
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string str1, str2;

    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    if (str1.length() != str2.length()) {
        cout << "The strings are not anagrams." << endl;
        return 0;
    }

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if (str1 == str2) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
