#include <iostream>
#include <vector>
#include <algorithm>

// Function to sort the elements of each bucket
void bucketSort(std::vector<float>& arr, int n) {
    // Create n empty buckets
    std::vector<std::vector<float>> buckets(n);

    // Find the maximum value in arr for normalization
    float max_value = *std::max_element(arr.begin(), arr.end());

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = std::min(static_cast<int>(n * arr[i] / max_value), n - 1); // Ensure bucketIndex is within bounds
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<float> arr(n);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    bucketSort(arr, n);

    std::cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

