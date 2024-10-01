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
