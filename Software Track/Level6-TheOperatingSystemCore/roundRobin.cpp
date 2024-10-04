/*
    You are tasked with simulating the Round Robin scheduling algorithm for process management. 
    Each process has an associated execution time, and all processes share a common time quantum. 
    Your goal is to calculate the average waiting time for all processes based on the Round Robin scheduling.

    Input:
    An integer n, representing the number of processes.
    An integer quantum, representing the time quantum for each process.
    A list of tuples containing process ID and execution time for each process in the format:
    [(processID1, execTime1), (processID2, execTime2), ..., (processIDn, execTimen)].

    Output:
    The average waiting time for all processes.

    Definitions:
    - Waiting time for each process is the total time that the process has to wait before its execution starts.
    - The average waiting time is the sum of all waiting times divided by the number of processes.

    Execution Rule:
    - Processes are executed in a cyclic order.
    - Each process is allowed to execute for a maximum of quantum time units.
    - If a process does not finish in its allocated quantum, it is placed at the end of the queue and will be executed again in the next cycle.

    Example:
    Input:
    n = 4
    quantum = 2
    processes = [(1, 4), (2, 2), (3, 1), (4, 5)]

    Output:
    5.75

    Explanation:
    At time 0, Process 1 starts and runs for 2 units of time (time 0 to 2). Remaining time: 2.
    At time 2, Process 2 starts and runs for 2 units of time (time 2 to 4). Remaining time: 0. Process 2 finishes.
    At time 4, Process 3 starts and runs for 1 unit of time (time 4 to 5). Remaining time: 0. Process 3 finishes.
    At time 5, Process 4 starts and runs for 2 units of time (time 5 to 7). Remaining time: 3.
    At time 7, Process 1 resumes and runs for 2 units of time (time 7 to 9). Remaining time: 0. Process 1 finishes.
    At time 9, Process 4 resumes and runs for 2 units of time (time 9 to 11). Remaining time: 1.
    At time 11, Process 4 resumes and runs for 1 unit of time (time 11 to 12). Remaining time: 0. Process 4 finishes.

    Total waiting time:
    Process 1: 5 (waited from 2 to 7)
    Process 2: 2 (waited from 2 to 4)
    Process 3: 4 (waited from 2 to 5)
    Process 4: 7 (waited from 3 to 5 and 9 to 11)
    Total waiting time = 5 + 2 + 4 + 7 = 18

    Average waiting time: 18 / 4 = 4.5

*/

// WRITE YOUR CODE HERE