/*
    You're working with a processor's pipeline, and the task is to optimize register usage during instruction execution. 
    Given a sequence of assembly-like instructions that use registers, find out which register is used the most and how many times it is used.

    Each instruction is represented as a string, where registers are in the format R1, R2, etc.

    Input:
    A list of strings where each string represents an instruction and includes register names.

    Output:
    A string representing the most frequently used register and the number of times it was used.

    Example
    Input
    instructions = ["MOV R1, R2", "ADD R1, R3", "SUB R2, R1", "MOV R1, R3"]

    Output
    "R1: 4"

    [Register R1 is used 4 times across all instructions.]

*/

// WRITE YOUR CODE HERE