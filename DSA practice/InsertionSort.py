def insertion_sort(arr):
    # Traverse through elements in the array starting from the second element
    for i in range(1, len(arr)):
        # Store the current element as the key to be placed in the sorted part
        key = arr[i]
        
        # Initialize j to the index of the last element in the sorted part
        j = i - 1

        # Move elements of arr[0..i-1] that are greater than key one position ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]  # Shift element to the right
            j -= 1

        # Place the key after the last element that was greater than it
        arr[j + 1] = key

# Example usage
arr = [12, 11, 13, 5, 6]
insertion_sort(arr)
print(arr)  # Output: [5, 6, 11, 12, 13]
