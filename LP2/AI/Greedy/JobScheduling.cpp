#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int AT;  // Arrival Time
    int BT;  // Burst Time
    int CT;  // Completion Time
    int TAT; // Turnaround Time
    int WT;  // Waiting Time
    bool completed;
};

void takeInput(vector<Process> &processes, int &n) {
    cout << "Enter number of processes: ";
    cin >> n;
    processes.resize(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> processes[i].AT >> processes[i].BT;
        processes[i].pid = i + 1;
        processes[i].completed = false;
    }
}

void schedule(vector<Process> &processes, int n) {
    int time = 0, completed = 0;

    while (completed != n) {
        int idx = -1;
        int minBurst = 1e9;

        for (int i = 0; i < n; i++) {
            if (processes[i].AT <= time && !processes[i].completed) {
                if (processes[i].BT < minBurst) {
                    minBurst = processes[i].BT;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            processes[idx].CT = time + processes[idx].BT;
            processes[idx].TAT = processes[idx].CT - processes[idx].AT;
            processes[idx].WT = processes[idx].TAT - processes[idx].BT;
            processes[idx].completed = true;
            time = processes[idx].CT;
            completed++;
        } else {
            time++; // CPU idle
        }
    }
}

void showTable(const vector<Process> &processes) {
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < processes.size(); i++) {
        cout << processes[i].pid << "\t"
             << processes[i].AT << "\t"
             << processes[i].BT << "\t"
             << processes[i].CT << "\t"
             << processes[i].TAT << "\t"
             << processes[i].WT << endl;
    }
}

int main() {
    int n;
    vector<Process> processes;

    takeInput(processes, n);
    schedule(processes, n);
    showTable(processes);

    return 0;
}


/*
Example 
--------

Enter number of processes: 3
Enter Arrival Time and Burst Time for Process 1: 0 3
Enter Arrival Time and Burst Time for Process 2: 2 5
Enter Arrival Time and Burst Time for Process 3: 1 1

PID	AT	BT	CT	TAT	WT
1	0	3	3	3	0
2	2	5	9	7	2
3	1	1	4	3	2

Formulas
--------
ArrivalTime(AT)
BurstTime(BT)
CompletionTime (CT) = time when a process finishes execution 
TurnAroundTime (TAT) = time elapsed between the arrival of a process and its completion = CT - AT
Waiting Time = duration in the ready queue before it begins executing = TAT - BT
*/
