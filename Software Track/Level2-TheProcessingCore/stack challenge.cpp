/*
    You're deep in the CPU's core, and the system overloaded due to a recursive process causing stack overflow. 
    Your mission is to manage the stack efficiently by simulating the execution of nested function calls, preventing the system from overflowing and crashing.

    Given a sequence of function calls represented as a string where each F represents a function being called and each R represents a function returning, your task is to:

    Simulate the process of function calls and returns.
    Ensure that no more than a certain number of recursive calls are active at any given time to prevent a stack overflow. If at any point, the depth of recursion exceeds a given threshold T, the system should issue a stack overflow warning.
    Your goal is to check if the system is safe or if it overflows and crashes due to excessive recursion.

    Example
    Input 1
    Function calls: "FFF R FR R FF R"
    Recursion Threshold (`T`): 3

    Output 1
    Safe: Yes

    [The maximum recursion depth reached is 3, which is equal to the threshold, so the system remains safe.]

    Input 2
    Function calls: "FFFF R F R RR"
    Recursion Threshold (`T`): 3

    Output 2
    Safe: No, Stack Overflow Occurred
    [The maximum recursion depth reached was 4, which exceeds the threshold of 3, leading to a stack overflow.]

*/

// WRITE YOUR CODE HERE