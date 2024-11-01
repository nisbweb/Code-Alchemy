#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Find Two Numbers in a Sorted Array that Add Up to a Target

    Given a sorted array of integers, find two numbers such that they add up
    to a specific target. Return the indices of the two numbers or a pair
    of -1 if no such numbers exist.

    Example:
    Input: nums = {2, 3, 5, 8, 11, 15}, target = 10
    Output: Indices: 1 and 3, Numbers: 3 and 8
*/

pair<int, int> twoSum(vector<int>& nums, int target) {
    int left = 0;               // Initialize left pointer
    int right = nums.size() - 1; // Initialize right pointer

    // Loop until the two pointers meet
    while (left < right) {
        int sum = nums[left] + nums[right]; // Calculate the sum of two numbers

        // If sum equals the target, return the indices
        if (sum == target) {
            return {left, right}; 
        } 
        // If sum is less than the target, move the left pointer to the right
        else if (sum < target) {
            left++;  
        } 
        // If sum is greater than the target, move the right pointer to the left
        else {
            right--; 
        }
    }

    // Return {-1, -1} if no such pair exists
    return {-1, -1}; 
}

int main() {
    vector<int> nums = {2, 3, 5, 8, 11, 15}; // Sorted array
    int target = 10;

    pair<int, int> result = twoSum(nums, target);

    // Check if a valid pair was found
    if (result.first != -1) {
        cout << "Indices: " << result.first << " and " << result.second << endl;
        cout << "Numbers: " << nums[result.first] << " and " << nums[result.second] << endl;
    } else {
        cout << "No pair found." << endl;
    }

    return 0;
}
