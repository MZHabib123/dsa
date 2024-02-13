//print the name N times
#include<iostream>
using namespace std;
int printName(int a){
    if(a==5) {return -1;}
    cout<<"zaid"<<endl;
    printName(a+1);
}
int main(){
    cout<<"hello"<<endl;
    int a=0;
    printName(0);
    return 0;
}