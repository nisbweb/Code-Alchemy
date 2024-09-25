/*
    The Matrix Nexus is facing a resource allocation issue, where certain sections of the grid consume more resources than others. 
    You need to optimize this by identifying the contiguous sub-matrix that has the maximum sum. This will help allocate resources efficiently and restore balance in the system. 
    Your task is to extend Kadane's Algorithm to a 2D matrix and find the maximum sum subarray.

    Task:
    Given an n x m matrix of integers (which can include negative numbers), your goal is to find the sub-matrix (contiguous block) that has the largest sum of its elements. 
    You will implement a 2D version of Kadane’s Algorithm to solve this problem.

    Input:
    An integer matrix grid of size n x m.
    Output:
    The maximum sum of a sub-matrix within the grid.

    Example:
    Input:
    grid = [
    [1, -2, -1, 4],
    [-5, 6, 3, -2],
    [3, 2, 1, -3]
    ]

    Output:
    12

    Explanation:
    The sub-matrix with the maximum sum is:
    [
    [6, 3],
    [2, 1]
    ]
    The sum of this sub-matrix is 6 + 3 + 2 + 1 = 12.
*/

// WRITE YOUR CODE HERE