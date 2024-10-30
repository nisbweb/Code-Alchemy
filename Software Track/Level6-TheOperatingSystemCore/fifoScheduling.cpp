/*
    You are tasked with simulating the First-In-First-Out (FIFO) scheduling algorithm for process execution. 
    Each process arrives in the order it is listed, and you need to calculate the average waiting time of all processes.

    Input:
    An integer n, representing the number of processes.
    A list of process IDs and their respective execution times in the format:
    [(processID1, execTime1), (processID2, execTime2), ..., (processIDn, execTimen)].

    Output:
    The average waiting time for all processes.

    Definitions:
    - Waiting time is the total time a process has to wait before its execution starts. The first process always has a waiting time of 0.
    - The average waiting time is the sum of all waiting times divided by the number of processes.

    Example 1:
    Input:
    n = 4
    processes = [(1, 3), (2, 2), (3, 4), (4, 5)]

    Output:
    4.5

    Explanation:
    Process 1 starts immediately and waits 0 units of time.
    Process 2 starts after Process 1 finishes, waiting 3 units of time.
    Process 3 starts after Process 2 finishes, waiting 3 + 2 = 5 units of time.
    Process 4 starts after Process 3 finishes, waiting 3 + 2 + 4 = 9 units of time.
    Total waiting time: 0 + 3 + 5 + 9 = 17

    Average waiting time: 17 / 4 = 4.25
*/


// WRITE YOUR CODE HERE


#include <iostream>
#include <vector>
using namespace std;

double calculateAverageWaitingTime(int n, const vector<pair<int, int>> &processes) {
    int totalWaitingTime = 0;
    int waitingTime = 0;

    for (int i = 1; i < n; ++i) {
       
        waitingTime += processes[i - 1].second;
        totalWaitingTime += waitingTime;
    }

    
    return static_cast<double>(totalWaitingTime) / n;
}

int main() {
    int n = 4;
    vector<pair<int, int>> processes = {{1, 3}, {2, 2}, {3, 4}, {4, 5}};
    
    double avgWaitingTime = calculateAverageWaitingTime(n, processes);
    cout << "Average Waiting Time: " << avgWaitingTime << endl; 

    return 0;
}
