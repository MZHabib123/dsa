#include<bits/stdc++.h>
using namespace std;
int main(){
//pairs
   pair<int,int>p={1,3};  //declare
   cout<<p.first<<" "<<p.second<<" "<<endl;
   pair<int,pair<int,int>>pp={1,{1,3}};
   cout<<pp.first<<" "<< pp.second.first<<" "<<pp.second.second<<endl;

   pair<int,int>arr[4]={{1,2},{2,3},{3,4},{5,1}};
   for(int i=0;i<4;i++){
    cout<<"{"<<arr[i].first<<" "<<arr[i].second<<"}"<<",";
   }  
   return 0; 
}