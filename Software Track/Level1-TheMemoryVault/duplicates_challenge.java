/*
    2. The system has identified that some of the memory sectors contain duplicated data blocks. Your task is to traverse the memory and remove unnecessary duplicates, 
       restoring the memory to its proper state.

    Given an array of integers representing data block IDs, some of which are duplicated, your task is to eliminate all duplicate blocks, leaving only unique ones. 
    The remaining blocks should be returned in sorted order.

    Input:
    - An integer n, representing the number of data blocks.
    - A list of n integers, where each integer represents a data block ID. Some data block IDs may be duplicated.

    Output:
    - A list of unique data block IDs sorted in ascending order.

    Example:
    Input:
    n = 8
    data_blocks = [4, 2, 4, 1, 3, 2, 5, 3]

    Output:
    [1, 2, 3, 4, 5]

*/


// WRITE YOUR CODE HERE
import java.util.*;
public class duplicates_challenge {
    public static int[] main1(int[] data_blocks) {
        data_blocks=sort(data_blocks);
        ArrayList<Integer> out=new ArrayList<>();
        for (int i : data_blocks) {
            if (!out.contains(i)) {
                out.add(i);
            }
        }
        return out.stream().mapToInt(Integer::intValue).toArray();
    }
    public static int[] sort(int[] n) {
        int temp,j;
        for (int i = 0; i < n.length; i++) {
            j=i;
            while (j>=1) {
                if (n[j]<n[j-1]) {
                    temp=n[j];
                    n[j]=n[j-1];
                    n[j-1]=temp;
                }
                j--;
            }
        }
        return n;
    }
    public static void main(String[] args) {
        int[] data_blocks={4, 2, 4, 1, 3, 2, 5, 3};
        System.out.println("Solution:"+Arrays.toString(main1(data_blocks)));
    }
}
