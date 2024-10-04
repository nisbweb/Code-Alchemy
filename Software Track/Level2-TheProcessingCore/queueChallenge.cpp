/*
    Queue Challenge: Task Scheduling in the Core
    The core is overwhelmed with too many tasks at once, and some tasks need to be processed before others. 
    Use a queue-based approach to manage the tasks and ensure they are processed in the correct order while optimizing CPU usage.

    Problem Statement:
    You are given a series of tasks represented as integers. The CPU can execute one task at a time, and certain tasks depend on the completion of others (task dependencies). 
    Implement a task scheduler using a queue to ensure tasks are processed in the correct order and as efficiently as possible.

    Input:
    An integer n, representing the number of tasks.
    A list of n task IDs.
    A list of dependency pairs where task A must be completed before task B.

    Output:
    A list representing the correct order of task execution, or a message if it is not possible to execute all tasks due to circular dependencies.

    Example
    Input
    n = 4
    tasks = [1, 2, 3, 4]
    dependencies = [(1, 2), (1, 3), (2, 4), (3, 4)]

    Output
    Task Execution Order: [1, 2, 3, 4]

    In the case that execution is not possible
    Output: Not possible to execute all tasks
*/

// WRITE YOUR CODE HERE