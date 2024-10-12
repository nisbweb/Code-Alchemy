/*
    Reverse Words in a String
    Write a program to reverse the words in a given string. The input string contains words separated by spaces, but the words themselves should not be reversed, only their order.

    Input:
    A string with words separated by spaces.

    Output:
    A string with the words reversed in order.

    Example 1:
    Input:
    "hello world"
    Output:
    "world hello"

    Example 2:
    Input:
    "data structures and algorithms"
    Output:
    "algorithms and structures data"
*/

// WRITE YOUR CODE HERE

import java.util.Scanner;

public class reverseWords {
    public static String revWords(String s) {
        String[] words=s.split(" ");
        String out="";
        for (int i = words.length-1; i >= 0 ; i--) {
            out=out+words[i];
            if (i!=0) {
                out=out+" ";
            }
        } 
        return out;
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the string: ");
        String s=in.nextLine();
        System.out.println(revWords(s));
    }
}