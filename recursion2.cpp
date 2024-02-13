//print from 1 to N using backtracking
#include<iostream>
using namespace std;
void printNum(int i,int n) {
    if(i>n){return;}
    printNum(i+1,n);
    cout<<i;
}
int main() {
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    printNum(0,n);
    return 0;
}



