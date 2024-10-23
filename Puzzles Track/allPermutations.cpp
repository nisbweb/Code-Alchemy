/*
    Given a string, generate all its permutations.
    This is a good example of recursive problem-solving, using backtracking 
    to generate each permutation by swapping characters.
    
    Input:
    A single string.

    Output:
    A list of all permutations of the input string. The output is sorted 
    lexicographically for better readability.

    Example 1:
    Input:
    "abc"

    Output:
    abc
    acb
    bac
    bca
    cab
    cba

    Example 2:
    Input:
    "aab"

    Output:
    aab
    aba
    baa

    Example 3:
    Input:
    "dog"

    Output:
    dgo
    dog
    gdo
    god
    odg
    ogd
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Function to generate all permutations using backtracking
void permuteHelper(std::string &str, int left, int right, std::vector<std::string> &result) {
    // Base case: if left index is the same as right, we've found a permutation
    if (left == right) {
        result.push_back(str);
        return;
    }

    // Recursive case: swap characters to generate permutations
    for (int i = left; i <= right; ++i) {
        std::swap(str[left], str[i]);       // Swap current index with the left index
        permuteHelper(str, left + 1, right, result);  // Recurse for the rest of the string
        std::swap(str[left], str[i]);       // Backtrack to the original configuration
    }
}

// Function to generate all permutations of a string
std::vector<std::string> generatePermutations(std::string str) {
    std::vector<std::string> result;
    permuteHelper(str, 0, str.size() - 1, result);
    std::sort(result.begin(), result.end()); // Sort permutations for easier readability
    return result;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    std::vector<std::string> permutations = generatePermutations(input);

    std::cout << "All permutations of the string are:\n";
    for (const auto &perm : permutations) {
        std::cout << perm << "\n";
    }

    return 0;
}
