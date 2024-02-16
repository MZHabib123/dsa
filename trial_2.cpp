#include<iostream>
#include <climits>
using namespace std;

struct prog {
    int p;
    int bt;
    int at;
};

void sort(prog p[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[j].at < p[i].at) {
                swap(p[j], p[i]);
            }
        }
    }
}

void sjf(prog p[], int n, int wt[], int ct[], int tat[]) {
    // Sort processes by arrival time
    sort(p, n);

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        ct[i] = 0;
        wt[i] = 0;
        tat[i] = 0;
    }

    int total_time = 0;
    int completed = 0;

    while (completed < n) {
        int shortest_index = -1;
        int shortest_bt = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= total_time && !wt[i] && p[i].bt < shortest_bt) {
                shortest_index = i;
                shortest_bt = p[i].bt;
            }
        }

        if (shortest_index == -1) {
            total_time++;
        } else {
            ct[shortest_index] = total_time + p[shortest_index].bt;
            tat[shortest_index] = ct[shortest_index] - p[shortest_index].at;
            wt[shortest_index] = tat[shortest_index] - p[shortest_index].bt;
            total_time += p[shortest_index].bt;
            completed++;
        }
    }
}

void displayResults(prog p[], int n, int ct[], int tat[], int wt[]) {
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].p << "\t" << p[i].at << "\t\t"
             << p[i].bt << "\t\t" << ct[i] << "\t\t"
             << tat[i] << "\t\t" << wt[i] << endl;
    }
}

int main() {
    int n = 5;
    prog processes[n] = {{1, 6, 2}, {2, 2, 5}, {3, 8, 1}, {4, 3, 0}, {5, 4, 4}};

    int ct[n];
    int tat[n];
    int wt[n];
    sjf(processes, n, wt, ct, tat);
    displayResults(processes, n, ct, tat, wt);

    return 0;
}
