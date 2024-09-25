/*
    The Matrix Nexus has several blocked data pathways, causing inefficiencies. 
    You need to find the shortest path from the top-left to the bottom-right corner of the matrix while avoiding obstacles.

    Task:
    Given a matrix of n x m, where 0 represents an open cell and 1 represents a blocked cell, determine the shortest path from the top-left corner to the bottom-right corner. 
    You can move up, down, left, or right.

    Input:
    An integer matrix grid where 0 is a free cell and 1 is an obstacle.
    Output:
    The length of the shortest path, or -1 if no path exists.

    Example 1:
    Input:
    grid = [
    [0, 1, 0],
    [0, 0, 0],
    [1, 0, 0]
    ]
    Output:
    4
    Explanation:
    The shortest path is [(0,0), (1,0), (1,1), (2,1), (2,2)] with a length of 4.

    Example 2:
    Input:
    grid = [
    [0, 1],
    [1, 0]
    ]

    Output:
    -1
    Explanation:
    There is no valid path from the top-left to the bottom-right.

*/

// WRITE YOUR CODE HERE