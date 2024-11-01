import java.util.Scanner;

public class linearSearch {
    public static int Lsearch(int[] arr, int s) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i]==s) {
                return i;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number of elements:");
        int n = in.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the elements");
        for (int i = 0; i < n; i++) {
            arr[i]=in.nextInt();
        }
        System.out.println("Enter the elements to be searched:");
        int s= in.nextInt();
        int status=Lsearch(arr, s);
        if (status>=0) {
            System.out.println("Element is present at"+status);
        }
        else {
            System.out.println("Element not found");
        }
    }
}