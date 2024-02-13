#include<iostream>
using namespace std;
 bool isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }
        else if (n%2==1){
            return false;
        }
        else{
         n=n/2;
        isPowerOfTwo(n);
        }
        return true;
        }

int main(){
    int n ;
    cout<<"enter";
    cin>>n;
    isPowerOfTwo(n);
    return 0;
}        