//check if string is pallindrome
#include <iostream>
using namespace std;

bool pallimdromeString(string s,int i,int n){
if(i<n/2)
{
if(s[i]!=s[n-i-1])
return false;
pallimdromeString(s,i+1,n);
}
return true;
}
int main(){
string s ="abba";
int n=s.length();
cout<<pallimdromeString(s,0,n);
}