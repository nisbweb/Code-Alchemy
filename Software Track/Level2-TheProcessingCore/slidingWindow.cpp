/*
    Sliding Window Challenge
    The CPU is processing data streams in real-time, and to optimize its performance, you need to manage these streams efficiently. 
    You’ve encountered a critical bottleneck: large chunks of data are being processed in sequence, but processing them all at once is causing significant delays. 
    Your task is to find a solution by applying the sliding window technique to streamline data processing and minimize delays.

    You must develop an algorithm that finds the maximum sum of a subarray of length k from a given data stream (represented as an array of integers). 
    This optimization will help the CPU manage the data in smaller chunks, reducing the processing time and improving system efficiency.

    Input
    An integer array arr[], representing the data stream.
    An integer k, representing the length of the sliding window.

    Output
    The maximum sum of a subarray of length k.

    Example
    Input
    arr[] = [1, 3, -1, -3, 5, 3, 6, 7]
    k = 3

    Output
    16
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the maximum sum of a subarray of size k
int maxSumSubarray(const vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) {
        cout << "Invalid input: The size of the array should be greater than or equal to k." << endl;
        return INT_MIN;
    }

    // Initialize the maximum sum and the current window sum
    int max_sum = INT_MIN;
    int current_sum = 0;

    // Compute the sum of the first window of size k
    for (int i = 0; i < k; i++) {
        current_sum += arr[i];
    }

    // Update the max_sum with the sum of the first window
    max_sum = current_sum;

    // Slide the window across the array
    for (int i = k; i < n; i++) {
        // Slide the window by subtracting the first element of the previous window
        // and adding the new element of the current window
        current_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    int n, k;
    
    // Input the array size
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);

    // Input the array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input the size of the sliding window
    cout << "Enter the size of the sliding window (k): ";
    cin >> k;

    // Call the function and print the result
    int result = maxSumSubarray(arr, k);
    if (result != INT_MIN) {
        cout << "The maximum sum of a subarray of size " << k << " is: " << result << endl;
    }

    return 0;
}