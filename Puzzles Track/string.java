/*
    First Unique Character in a String
    Given a string s, find the first non-repeating character and return its index. If it does not exist, return -1.

    Input:
    A string s.
    Output:
    The index of the first unique character or -1.

    Example:
    Input:
    "hacktoberfest"

    Output:
    0
*/

// WRITE YOUR CODE HERE

import java.util.*;

public class string {
    public static int indexOfFirstUniqChar(String s) {
        LinkedHashMap<Character, Integer> m=new LinkedHashMap<>();
        for (char ch : s.toCharArray()) {
            m.put(ch, m.getOrDefault(ch, 0)+1);
        }
        System.out.println(m);
        for (int i = 0; i < s.length(); i++) {
            char ch=s.charAt(i);
            if (m.get(ch)==1) {
                return i;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the string: ");
        String s=in.nextLine();
        System.out.println(indexOfFirstUniqChar(s));
    }
}