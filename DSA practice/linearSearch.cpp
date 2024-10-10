#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==target){
            return i;
        }
    }

    return -1;
    
    
}

int main() {
    int arr[]= {1,5,2,53,62,2,7,3,8,4,52,6};
  
    int target=8;
  
    cout<<linearSearch(arr, 12, 6);

    return 0;
}
