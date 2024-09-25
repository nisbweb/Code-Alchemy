/*
    At the lowest level of the CPU’s processing core, bits are misaligned, causing incorrect data processing. Your task is to use bit manipulation to toggle, flip, and correct specific bits to restore proper functionality.

    You are given a 32-bit unsigned integer n and a list of operations that need to be applied to this integer. The operations include:
    - Toggle the bit at a given position p.
    - Flip a specific range of bits between two positions.
    - Set a bit at a given position to 1 if it’s 0 or to 0 if it’s 1.

    After applying these operations, your task is to return the final value of the integer.

    Example
    Input
    n = 29
    operations = [
        ("toggle", 3),
        ("flip_range", 0, 4),
        ("set", 1)
    ]

    Output
    00000000000000000000000000000100

    Explanation
    Original n in binary: 00000000000000000000000000011101
    1. Toggle bit at position 3: 00000000000000000000000000011001
    2. Flip bits from position 0 to 4: 00000000000000000000000000000110
    3. Set bit at position 1: 00000000000000000000000000000100
    Final n: 00000000000000000000000000000100
*/

// WRITE YOUR CODE HERE