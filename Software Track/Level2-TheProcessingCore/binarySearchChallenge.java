/*
    Binary Search Challenge: Optimizing Memory Access
    You have a sorted array of memory addresses. Implement a binary search algorithm to quickly locate a specific address.

    Example
    Input
    memory_addresses = [101, 202, 303, 404, 505, 606, 707]
    target = 404

    Output
    Address Found at Index: 3
*/

// WRITE YOUR CODE
public class binarySearchChallenge {
    public static int BinarySearch(int[] arr, int num) {
        int max=arr.length-1;
        int min=0;
        while (min<=max) {
            int mid=min+(max-min)/2;
            if (arr[mid]==num) {
                return mid;
            }
            if (arr[mid]>num) {
                max-=1;
            } else {
                min+=1;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] memory_addresses={101, 202, 303, 404, 505, 606, 707};
        int target=404;
        System.out.println(BinarySearch(memory_addresses, target));
    }
}
