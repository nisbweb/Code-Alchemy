/*
    The network paths are sorted in ascending order based on node IDs, but due to disruptions, some critical nodes are malfunctioning and causing broken connections. 
    To restore the network, you need to quickly identify these malfunctioning nodes and reconnect them.

    You are tasked with using binary search to efficiently locate the broken nodes within the sorted network paths and return their positions. 
    After identifying the malfunctioning nodes, reestablish connections by removing or replacing them from the network.

    Input:
    A sorted list of network node IDs.
    A list of IDs representing broken nodes that need to be identified.

    Output:
    A list of indices representing where the broken nodes were found in the sorted network paths.
    If a broken node is not found, return -1 for that node.

    Example
    Input:
    network_nodes = [1001, 1003, 1005, 1007, 1010, 1013, 1016]
    broken_nodes = [1005, 1013, 1020]

    Output:
    [2, 5, -1]
*/

// WRITE YOUR CODE
import java.util.*;;
public class binarySearchChallenge {
    public static int[] returnFaulty(int[] network_nodes, int[] broken_nodes) {
        ArrayList<Integer> out=new ArrayList<>();
        for (int i : broken_nodes) {
            out.add(search(network_nodes, i));
        }
        return out.stream().mapToInt(Integer::intValue).toArray();
    }
    public static int search(int[] arr, int num) {
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
        int[] network_nodes={1001, 1003, 1005, 1007, 1010, 1013, 1016};
        int[] broken_nodes={1005, 1013, 1020};
        System.out.println(Arrays.toString(returnFaulty(network_nodes, broken_nodes)));
    }
}
