/*
    Sliding Window Challenge
    The CPU is processing data streams in real-time, and to optimize its performance, you need to manage these streams efficiently. 
    You’ve encountered a critical bottleneck: large chunks of data are being processed in sequence, but processing them all at once is causing significant delays. 
    Your task is to find a solution by applying the sliding window technique to streamline data processing and minimize delays.

    You must develop an algorithm that finds the maximum sum of a subarray of length k from a given data stream (represented as an array of integers). 
    This optimization will help the CPU manage the data in smaller chunks, reducing the processing time and improving system efficiency.

    Input
    An integer array arr[], representing the data stream.
    An integer k, representing the length of the sliding window.

    Output
    The maximum sum of a subarray of length k.

    Example
    Input
    arr[] = [1, 3, -1, -3, 5, 3, 6, 7]
    k = 3

    Output
    16
*/

// WRITE YOUR CODE HERE