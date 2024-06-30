# Process Scheduling Simulation and Deadlock Detection

This repository contains two C++ programs:
- Process Scheduling Simulation: Simulates process scheduling using First Come First Serve (FCFS) algorithm and calculates waiting times, turnaround times, and displays a Gantt chart.
- Deadlock Detection: Detects deadlock in a system using a resource allocation graph approach.

## Instructions
Running the Process Scheduling Simulation
Compile: Compile the program using a C++ compiler. For example, using g++:

- clone the repository in your local machine
- ensure that the cpp compiler is installed
- run the following command to convert to .exe file

```bash
  g++ -o process_scheduling process_scheduling.cpp
```
Execute: Run the compiled executable:

bash

    ./process_scheduling

Input: Follow the prompts to enter the number of processes, arrival times, and burst times for each process. The simulation will calculate and display scheduling details, including a Gantt chart.

Running the Deadlock Detection Program

Compile: Compile the program using a C++ compiler. For example, using g++:
```
g++ -o deadlock_detection deadlock_detection.cpp
```
Execute: Run the compiled executable:

bash

    ./deadlock_detection

Input: Follow the prompts to enter the number of processes, number of resources, process IDs, resource IDs, allocation matrix, and request matrix. The program will determine if a deadlock exists based on the resource allocation graph.

Example Inputs
Process Scheduling Simulation


```
Enter number of processes: 3
Enter arrival time and burst time for each process:
Process 1:
Arrival time: 0
Burst time: 5
Process 2:
Arrival time: 1
Burst time: 3
Process 3:
Arrival time: 2
Burst time: 4
```
Deadlock Detection

```

Enter number of processes: 3
Enter number of resources: 3
Enter process IDs:
1 2 3
Enter resource IDs:
A B C
Enter allocation matrix:
0 1 0
1 0 1
0 0 2
Enter request matrix:
0 0 1
2 0 0
0 1 0
```
Output

Process Scheduling Simulation: Displays a Gantt chart and detailed process scheduling information, including average waiting time and average turnaround time.
Deadlock Detection: Outputs whether a deadlock is detected in the system based on the provided resource allocation and request matrices.

Notes

- These programs assume correct input format as described in the prompts. Ensure inputs adhere to the expected format to avoid errors.
- Both programs utilize basic C++ functionalities such as arrays, vectors, and recursion (for deadlock detection).
