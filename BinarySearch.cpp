#include<iostream>
using namespace std;

int binarySearch(int arr[],int size, int key){
    int start=0;
    int end=size-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return -1;
}

int main(){
    int even[6]={2,3,4,5,6,7};
    int odd[5]={1,2,3,4,5};
    int evenIndex = binarySearch(even,6,6);
    cout<<"the index of 6 is"<<evenIndex<<endl;
    int oddIndex = binarySearch(odd,6,5);
    cout<<"the index of 5 is"<<oddIndex<<endl;
    return 0;
}