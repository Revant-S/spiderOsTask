#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;

bool isDeadlock(int processes[], int resources[], int allocation[][3], int request[][3], int numProcesses, int numResources) {
    unordered_map<int, unordered_set<int>> graph;
    unordered_set<int> safeNodes;

    for (int i = 0; i < numProcesses; ++i) {
        graph[processes[i]] = {};
        for (int j = 0; j < numResources; ++j) {
            if (allocation[i][j] != 0 || request[i][j] != 0) {
                graph[processes[i]].insert(resources[j]);
            }
        }
    }

    for (const auto& node : graph) {
        unordered_set<int> visited;
        unordered_set<int> currentPath;

        function<bool(int)> dfsCycleDetection = [&](int current) {
            if (currentPath.find(current) != currentPath.end()) {
                return true;
            }
            if (visited.find(current) != visited.end()) {
                return false;
            }

            visited.insert(current);
            currentPath.insert(current);

            for (int neighbor : graph[current]) {
                if (dfsCycleDetection(neighbor)) {
                    return true;
                }
            }

            currentPath.erase(current);
            return false;
        };

        if (dfsCycleDetection(node.first)) {
            return true;
        }
    }

    return false;
}

int main() {
    int numProcesses, numResources;

    cout << "Enter number of processes: ";
    cin >> numProcesses;
    cout << "Enter number of resources: ";
    cin >> numResources;

    int processes[numProcesses];
    int resources[numResources];
    int allocation[numProcesses][3];
    int request[numProcesses][3];

    cout << "Enter process IDs:\n";
    for (int i = 0; i < numProcesses; ++i) {
        cin >> processes[i];
    }

    cout << "Enter resource IDs:\n";
    for (int i = 0; i < numResources; ++i) {
        cin >> resources[i];
    }

    cout << "Enter allocation matrix:\n";
    for (int i = 0; i < numProcesses; ++i) {
        for (int j = 0; j < numResources; ++j) {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter request matrix:\n";
    for (int i = 0; i < numProcesses; ++i) {
        for (int j = 0; j < numResources; ++j) {
            cin >> request[i][j];
        }
    }

    if (isDeadlock(processes, resources, allocation, request, numProcesses, numResources)) {
        cout << "\nDeadlock detected!\n";
    } else {
        cout << "\nNo deadlock detected.\n";
    }

    return 0;
}
