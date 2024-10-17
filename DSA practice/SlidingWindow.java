import java.util.*;
import java.util.ArrayDeque;
import java.util.Deque;


public class solution {
    
    public static void main(String[] args) {

        // Test case
        int[] nums = {1, 3, -1, -3, 5, 3, 6, 7};
        int k = 3;

        int[] result = maxSlidingWindow(nums, k);

        // Print the result
        System.out.println("Max sliding window: "+ Arrays.toString(result));
        
    }

    public static int[] maxSlidingWindow(int[] nums, int k) {
        int[] result = new int[nums.length - k + 1];
        int ri = 0;

        Deque<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < nums.length; i++) {
            // remove the numbers out of range K
            if (!queue.isEmpty() && queue.peek() == i - k) queue.poll();

            // remove the smaller numbers in K range
            while (!queue.isEmpty() && nums[queue.peekLast()] <= nums[i]) {
                queue.pollLast();
            }
            queue.offer(i);
            if (i >= k - 1) {
                result[ri++] = nums[queue.peek()];
            }
        }
        return result;
    }
}
