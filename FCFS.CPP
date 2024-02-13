#include<iostream>
using namespace std;
struct FCFS
{
    int arrival_time;
    int burst_time;
    int process_id;
};

void calculateTimes(FCFS processes[], int n, int completionTime[], int turnaroundTime[], int waitingTime[]) {
    completionTime[0] = processes[0].burst_time;
 
    turnaroundTime[0]=completionTime[0]-processes[0].arrival_time;
    
    // waitingTime[0]=turnaroundTime[0]-processes[0].burst_time;
    waitingTime[0]=0;
    

for (int i = 1; i < n; i++) {
        completionTime[i] = completionTime[i - 1] + processes[i].burst_time;
        turnaroundTime[i] = completionTime[i] - processes[i].arrival_time;
        waitingTime[i] = turnaroundTime[i] - processes[i].burst_time;
        if (waitingTime[i] < 0) {
            waitingTime[i] = 0;
        }
    }
}


void displayResults(FCFS processes[], int n, int completionTime[], int turnaroundTime[], int waitingTime[]) {
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i].process_id << "\t" << processes[i].arrival_time << "\t\t"
             << processes[i].burst_time<< "\t\t" << completionTime[i] << "\t\t"
             << turnaroundTime[i] << "\t\t" << waitingTime[i] << endl;
    }
}

int main(){
    int n=5;
    //   FCFS processes[n] = {{1, 0, 6}, {2, 2, 3}, {3, 5, 8}, {4, 9, 4}};
    FCFS processes[n] = {{2, 6, 1}, {5, 2, 2}, {1, 8, 3}, {0, 3, 4},{4,4,5}};
    int arrivalTime[n];
   for(int i=0;i<n;i++){
    cin>>arrivalTime[i];
   }
    int completionTime[n];int turnaroundTime[n], waitingTime[n];
    calculateTimes(processes, n, completionTime, turnaroundTime, waitingTime);
    displayResults(processes, n, completionTime, turnaroundTime, waitingTime);

    return 0;
}
