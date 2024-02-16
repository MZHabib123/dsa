#include <iostream>
using namespace std;
struct prog
{
    int p;
    int burst_time;
    int arrival_time;
};
void sortProcessesByArrivalTime(prog p[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[j].arrival_time < p[i].arrival_time)
            {
                swap(p[j], p[i]);
            }
        }
    }
}





void sjf(prog p[], int n, int wt[], int ct[], int tat[])
{
    wt[0] = 0;
    ct[0] = p[0].arrival_time + p[0].burst_time + wt[0];
    tat[0] = ct[0] - p[0].arrival_time;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[j].burst_time < p[i].burst_time && p[j].arrival_time <= ct[i - 1])
            {
                swap(p[i], p[j]);
            }
        }

        ct[i] = max(ct[i - 1], p[i].arrival_time) + p[i].burst_time;
        tat[i] = ct[i] - p[i].arrival_time;
        wt[i] = tat[i] - p[i].burst_time;
    }
}



void displayResults(prog p[], int n, int ct[], int tat[], int wt[])
{
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << p[i].p << "\t" << p[i].arrival_time << "\t\t"
             << p[i].burst_time << "\t\t" << ct[i] << "\t\t"
             << tat[i] << "\t\t" << wt[i] << endl;
    }
}






int main()
{
    int n = 5;
    prog processes[5] = {{1, 6, 2}, {2, 2, 15}, {3, 8, 1}, {4, 3, 0}, {5, 4, 4}};

    sortProcessesByArrivalTime(processes, n);

    int ct[n];
    int tat[n];
    int wt[n];
    sjf(processes, n, wt, ct, tat);
    displayResults(processes, n, ct, tat, wt);

    return 0;
}