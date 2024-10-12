/*
you will have to specify the number of elements you want to sort in a given array.

the first parameter is the array to be sorted
the second paraeter is the no of elements you need to sort. (usually the size of the array itself)

third is optional, it would specify the order of sorting 
*/


#include <bits/stdc++.h>
using namespace std;


void bubbleSort(int arr[],int size){
        
        for (int i = 0; i < size-1 ; i++)//for number of passes
        {
            for (int j = 0;j<size-i-1 ; j++)//for traversing the elements of the array
            {
             if(arr[j]>arr[j+1]){

                //swap
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

             }
            }
            
        }
}





//overloading bubbleSort, just because i can...

/*
if we pass 'a' as the third parameter
then it will sort the given array in the ascending order

if we pass 'd' as the third parameter
then it will sort the given array in the decending order

else...it will just terminate the code with a proper message..ig
*/

void bubbleSort(int arr[],int size,char order){
        
        if(order=='a'){
            for (int i = 0; i < size-1 ; i++)//for number of passes
           {
            for (int j = 0;j<size-i-1 ; j++)//for traversing the elements of the array
            {
             if(arr[j]>arr[j+1]){

                //swap
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

             }
            }
            
        }
        }
        else if(order=='d'){
            for (int i = 0; i < size-1 ; i++)//for number of passes
        {
            for (int j = 0;j<size-i-1 ; j++)//for traversing the elements of the array
            {
             if(arr[j]<arr[j+1]){

                //swap
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

             }
            }
            
        }
    }
         else{
            cout<<endl;
            cout<<"please specify a coherent order parameter";
            exit(0);
        }
      

}



void print_arr(int arr[5]){
    for (int i = 0; i < 5; i++)
    {
        cout<< arr[i]<< " ";
    }
    
}




int main(){

    int test_arr[5]={4,1,7,4,2};
    print_arr(test_arr);
    bubbleSort(test_arr,5,'a');
    cout<<endl;
    print_arr(test_arr);
    cout<<endl;


    return 0;
}

