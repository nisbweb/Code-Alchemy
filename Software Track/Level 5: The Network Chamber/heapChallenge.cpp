/*
    The network has experienced disruptions, and several connections need to be restored. However, not all connections are equally important. 
    High-priority connections, such as critical servers or emergency communication links, must be restored first to ensure minimal downtime for essential services.

    Your task is to implement a heap (priority queue) to manage the restoration of these network connections based on their priority levels. 
    Lower numbers indicate higher priority. Connections with higher priority should be restored before those with lower priority.

    Input:
    A list of tuples where each tuple contains a network connection ID and its priority level (lower numbers represent higher priority).
    The number of connections that need to be restored.

    Output:
    A list of connection IDs in the order they should be restored, from highest priority (lowest number) to lowest priority.

    Example
    Input:
    connections = [(1001, 3), (1002, 5), (1003, 2), (1004, 4), (1005, 1)]
    num_to_restore = 3

    Output:
    [1005, 1003, 1001]
*/

// WRITE YOUR CODE