/*
    Rotate Array
    Given an array, rotate the array to the right by k steps, where k is non-negative.

    Input:
    An array of integers and an integer k.
    Output:
    The rotated array.

    Example 1:
    Input:
    [1,2,3,4,5,6,7], k = 3

    Output:
    [5,6,7,1,2,3,4]
*/

// WRITE YOUR CODE HERE

import java.util.Arrays;
import java.util.Scanner;

public class rotateArray {
    public static int[] rotateArrayFromK(int[] arr, int k) {
        int[] out=new int[arr.length];
        int count = 0;
        for (int i = arr.length-k; i < arr.length; i++) {
            out[count]=arr[i];
            count++;
        }
        for (int i = 0; i < arr.length-k; i++) {
            out[k+i]=arr[i];
        }
        return out;
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the number of elements:");
        int n=in.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the elements of the array");
        for (int i = 0; i < n; i++) {
            arr[i]=in.nextInt();
        }
        System.out.println("Enter the value of K");
        int k=in.nextInt();
        System.out.println(Arrays.toString(rotateArrayFromK(arr, k)));
    }
}
