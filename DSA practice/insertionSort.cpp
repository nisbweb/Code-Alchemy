#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int start=0;start<n;start++){
        int min_index = start;
        for(int i=start+1;i<n;i++){
            if(arr[i]<arr[min_index]){
                min_index = i;
            }
        }
        swap(arr[start], arr[min_index]);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n ; i++){
        cin >> arr[i];
    }

    insertionSort(arr, n);
}
