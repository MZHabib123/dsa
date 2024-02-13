#include<iostream>
using namespace std;

// Structure to represent a process
struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
};

// Function to calculate completion time, turnaround time, and waiting time
void calculateTimes(Process processes[], int n, int completionTime[], int turnaroundTime[], int waitingTime[]) {
    completionTime[0] = processes[0].burstTime;

    for (int i = 1; i < n; i++) {
        // Calculate completion time
        completionTime[i] = completionTime[i - 1] + processes[i].burstTime;

        // Calculate turnaround time
        turnaroundTime[i] = completionTime[i] - processes[i].arrivalTime;

        // Calculate waiting time
        waitingTime[i] = turnaroundTime[i] - processes[i].burstTime;

        // Ensure waiting time is non-negative
        if (waitingTime[i] < 0) {
            waitingTime[i] = 0;
        }
    }
}

// Function to display the results
void displayResults(Process processes[], int n, int completionTime[], int turnaroundTime[], int waitingTime[]) {
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i].processID << "\t" << processes[i].arrivalTime << "\t\t"
             << processes[i].burstTime << "\t\t" << completionTime[i] << "\t\t"
             << turnaroundTime[i] << "\t\t" << waitingTime[i] << endl;
    }
}

int main() {
    // Number of processes
    const int n = 4;

    // Array to store process information
    Process processes[n] = {{1, 0, 6}, {2, 2, 3}, {3, 5, 8}, {4, 9, 4}};

    // Arrays to store completion time, turnaround time, and waiting time
    int completionTime[n], turnaroundTime[n], waitingTime[n];

    // Calculate times
    calculateTimes(processes, n, completionTime, turnaroundTime, waitingTime);

    // Display results
    displayResults(processes, n, completionTime, turnaroundTime, waitingTime);

    return 0;
}
