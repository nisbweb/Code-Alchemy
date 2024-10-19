#include <iostream>
using namespace std;

void selection_sort(int arr[], int n) // Accept both the array and its size
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i; // Start with the first unsorted element
        for (int j = i + 1; j < n; j++) // Find the minimum element in the remaining unsorted array
        {
            if (arr[j] < arr[min_index]) // If found a smaller element
            {
                min_index = j; // Update min_index
            }
        }
        // Swap the found minimum element with the first unsorted element
        if (min_index != i)
        {
            swap(arr[min_index], arr[i]);
        }
    }
}

int main()
{
    int arr[5] = {100, 78, 3, 9, 56};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    selection_sort(arr, n); // Pass the array and its size to the function

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

