/*
    Given an integer x, write a function to determine if x is a palindrome. An integer is a palindrome when it reads the same backward as forward.

    Input:
    A single integer.

    Output:
    Return true if the integer is a palindrome, false otherwise.

    Example 1:
    Input:
    121

    Output:
    true
*/

// WRITE YOUR CODE HERE
#include <iostream>
using namespace std;

bool isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;
    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }
    return originalNum == reversedNum;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }

    return 0;
}


