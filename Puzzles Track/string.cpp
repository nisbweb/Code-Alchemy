/*
    First Unique Character in a String
    Given a string s, find the first non-repeating character and return its index. If it does not exist, return -1.

    Input:
    A string s.
    Output:
    The index of the first unique character or -1.

    Example:
    Input:
    "hacktoberfest"

    Output:
    0
*/

// WRITE YOUR CODE HERE

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int firstUniqueChar(const string &s) {
    unordered_map<char, int> charCount;

   
    for (char ch : s) {
        charCount[ch]++;
    }

   
    for (int i = 0; i < s.size(); i++) {
        if (charCount[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string input = "hacktoberfest";
    cout << firstUniqueChar(input) << endl; 
    return 0;
}
