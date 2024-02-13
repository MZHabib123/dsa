#include <iostream>
using namespace std;
void reverseArray(int arr[],int i ,int n){

if(i<n/2)
{int x=arr[i];
arr[i]=arr[n-i-1];
arr[n-i-1]=x;
reverseArray(arr,i+1,n);
}

}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
reverseArray(arr,0,10);
for (int y=0;y<10;y++)
{cout<<arr[y]<<" ";
}
return 0;
}