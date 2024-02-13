#include <iostream>
#include<vector>
   using namespace std;
   vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>result;
        int n=candies.size();
        int count=0;

        for(int y=0;y<n;y++){
            for(int i=0;i<n;i++){
                if(candies[y]+extraCandies >= candies[i]){
                     count++;
                }
               
            }
            if(count==(n)){
            result.push_back(true);}
            else{
                result.push_back(false);
            }


        }
        return result;

    }
int main(){
    std::vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    kidsWithCandies(candies,extraCandies);
    int n=candies.size();
     
 
}