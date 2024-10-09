import java.util.Scanner;

public class insertionSort {
    public static int[] isort(int[] n) {
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
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number of elements:");
        int n = in.nextInt();
        int[] arr=new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i]=in.nextInt();
        }
        System.out.println("Sorted array: "+ isort(arr));
    }
}
