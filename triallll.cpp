#include<iostream>
#include <climits>
using namespace std;

struct SJF {
    int arrival_time;
    int burst_time;
    int process_id;
    bool done;
};

void sortProcessesByArrivalTime(SJF processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[j].arrival_time < processes[i].arrival_time) {
                SJF temp = processes[j];
                processes[j] = processes[i];
                processes[i] = temp;
            }
        }
    }
}

void sjf(SJF processes[], int n, int completionTime[], int turnaroundTime[], int waitingTime[]) {
    sortProcessesByArrivalTime(processes, n);

    int currentTime = 0;
    int totalCompleted = 0;

    while (totalCompleted < n) {
        int shortestJobIndex = -1;
        int shortestJobBurstTime = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!processes[i].done && processes[i].arrival_time <= currentTime && processes[i].burst_time < shortestJobBurstTime) {
                shortestJobIndex = i;
                shortestJobBurstTime = processes[i].burst_time;
            }
        }

        if (shortestJobIndex == -1) {
            currentTime++;
        } else {
            processes[shortestJobIndex].done = true;
            completionTime[shortestJobIndex] = currentTime + shortestJobBurstTime;
            turnaroundTime[shortestJobIndex] = completionTime[shortestJobIndex] - processes[shortestJobIndex].arrival_time;
            waitingTime[shortestJobIndex] = turnaroundTime[shortestJobIndex] - processes[shortestJobIndex].burst_time;
            currentTime += shortestJobBurstTime;
            totalCompleted++;
        }
    }
}

void displayResults(SJF processes[], int n, int completionTime[], int turnaroundTime[], int waitingTime[]) {
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i].process_id << "\t" << processes[i].arrival_time << "\t\t"
             << processes[i].burst_time << "\t\t" << completionTime[i] << "\t\t"
             << turnaroundTime[i] << "\t\t" << waitingTime[i] << endl;
    }
}

int main() {
    int n = 5;
    SJF processes[n] = {{2, 6, 1, false}, {5, 2, 2, false}, {1, 8, 3, false}, {0, 3, 4, false}, {4, 4, 5, false}};

    int completionTime[n] = {0};
    int turnaroundTime[n] = {0};
    int waitingTime[n] = {0};

    sjf(processes, n, completionTime, turnaroundTime, waitingTime);
    displayResults(processes, n, completionTime, turnaroundTime, waitingTime);

    return 0;
}
