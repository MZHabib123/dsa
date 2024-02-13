#include<iostream>
using namespace std;
struct SCHEDULING_ALGO
{
    int process_id;
    int burst_time;
    int arrival_time;
};
int calculateTimes(SCHEDULING_ALGO process[],int n,int completionTime[],int turnaroundTime[],int waitingTime[]){
    waitingTime[i]
    for(int i=0;i<n;i++){
        completionTime[i]=waitingTime[i]+process[i].burst_time;
        waitingTime[i]=completionTime[i]-process[i].arrival_time;
        
    }


}

void displayResults(SCHEDULING_ALGO process[],int n,int completionTime[],int turnaroundTime[],int waitingTime[]){

}

int main(){
   int n=4;
    SCHEDULING_ALGO process[n] = {{1, 0, 6}, {2, 2, 3}, {3, 5, 8}, {4, 9, 4}};
    int completionTime[n], turnaroundTime[n], waitingTime[n];
    calculateTimes(process, n, completionTime, turnaroundTime, waitingTime);
    displayResults(process, n, completionTime, turnaroundTime, waitingTime);

    return 0;
}
