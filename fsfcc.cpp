#include<iostream>
#include<algorithm>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int arrivalTime;
};

bool compareArrival(const Process &a, const Process &b) {
    return a.arrivalTime < b.arrivalTime;
}

int main()
{  
    int n;
    cout << "Number of processes: ";
    cin >> n;

    Process processes[n];
 
    cout << "\nProcess Burst Time\n";
    for(int i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]: ";
        processes[i].id = i + 1;
        cin >> processes[i].burstTime;
    }

    cout << "Enter arrival time of processes: ";
    for(int i = 0; i < n; i++){
        cin >> processes[i].arrivalTime;
    }

    // Sort processes based on arrival time
    sort(processes, processes + n, compareArrival);

    // Calculate waiting time, turnaround time, and completion time
    int wt[n], tat[n], ct[n];
    wt[0] = 0;
    ct[0] = processes[0].burstTime;
    tat[0] = ct[0] - processes[0].arrivalTime;

    for(int i = 1; i < n; i++)
    {
        wt[i] = max(0, ct[i - 1] - processes[i].arrivalTime);
        ct[i] = ct[i - 1] + processes[i].burstTime;
        tat[i] = ct[i] - processes[i].arrivalTime;
    }

    // Printing the table
    cout << "\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n";
    for(int i = 0; i < n; i++)
    {
        cout << "P[" << processes[i].id << "]\t" << processes[i].burstTime << "\t\t" << processes[i].arrivalTime << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t" << ct[i] << "\n";
    }
 
    return 0;
}
