/*
    You are tasked with simulating the First-In-First-Out (FIFO) scheduling algorithm, where each process has an associated arrival time. 
    You need to calculate the average waiting time for all processes, taking into account their arrival times.

    Input:
    An integer n, representing the number of processes.
    A list of tuples containing process ID, execution time, and arrival time for each process in the format:
    [(processID1, execTime1, arrivalTime1), (processID2, execTime2, arrivalTime2), ..., (processIDn, execTimen, arrivalTimen)].

    Output:
    The average waiting time for all processes.

    Definitions:
    - Waiting time for each process is the total time that the process has to wait after its arrival before its execution starts.
    - The average waiting time is the sum of all waiting times divided by the number of processes.
    Execution Rule:
    - The scheduler processes tasks in the order of arrival time. If multiple tasks arrive at the same time, the process listed first is executed first.

    Example:
    Input:
    n = 4
    processes = [(1, 3, 0), (2, 2, 1), (3, 4, 2), (4, 5, 3)]

    Output:
    4.75

    Explanation:
    Process 1 arrives at time 0, so it starts execution immediately and waits 0 units of time.
    Process 2 arrives at time 1, but Process 1 is still running. Process 2 waits until Process 1 finishes at time 3. So, Process 2 waits 3 - 1 = 2 units of time.
    Process 3 arrives at time 2, but Process 1 and 2 are ahead in the queue. Process 3 waits until Process 2 finishes at time 5. So, Process 3 waits 5 - 2 = 3 units of time.
    Process 4 arrives at time 3 and waits until Process 3 finishes at time 9. So, Process 4 waits 9 - 3 = 6 units of time.
    Total waiting time: 0 + 2 + 3 + 6 = 11

    Average waiting time: 11 / 4 = 2.75
*/


// WRITE YOUR CODE HERE