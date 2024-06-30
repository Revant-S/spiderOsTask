#include <iostream>
#include <vector>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int startTime;
    int finishTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateTimes(vector<Process>& processes) {
    int n = processes.size();
    int currentTime = 0;

    for (int i = 0; i < n; ++i) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        processes[i].startTime = currentTime;
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        processes[i].finishTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;

        currentTime += processes[i].burstTime;
    }
}

void printProcesses(const vector<Process>& processes) {
    cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (const auto& p : processes) {
        cout << p.id << "\t\t" << p.arrivalTime << "\t\t" << p.burstTime << "\t\t"
             << p.waitingTime << "\t\t" << p.turnaroundTime << endl;
    }
}

double calculateAverage(vector<Process>& processes, string type) {
    double total = 0;
    for (const auto& p : processes) {
        if (type == "waiting") {
            total += p.waitingTime;
        } else if (type == "turnaround") {
            total += p.turnaroundTime;
        }
    }
    return total / processes.size();
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        cout << "Process " << processes[i].id << ":\n";
        cout << "Arrival time: ";
        cin >> processes[i].arrivalTime;
        cout << "Burst time: ";
        cin >> processes[i].burstTime;
    }

    calculateTimes(processes);

    cout << "\nGantt Chart and Process Details:\n";
    printProcesses(processes);

    double avgWaitingTime = calculateAverage(processes, "waiting");
    double avgTurnaroundTime = calculateAverage(processes, "turnaround");

    cout << "\nAverage Waiting Time = " << avgWaitingTime << endl;
    cout << "Average Turnaround Time = " << avgTurnaroundTime << endl;

    return 0;
}
