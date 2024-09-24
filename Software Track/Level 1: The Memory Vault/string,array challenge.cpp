/*
    1. Array/String Challenge: The first task is to reorganize the fragmented data blocks using array and
    string manipulation. You need to scan through the memory sectors and arrange them in the correct
    order to ensure efficient data retrieval.

    Each memory sector contains a block of data represented as a string. However, the data blocks have been fragmented and shuffled out of order. 
    Your task is to rearrange these blocks by sorting them in ascending order based on their memory sector numbers.	
    Input : 
    - Integer n representing number of fragments/data. blocks.          
    - An array of n strings where each string is a memory sector. Each memory sector is prefixed by an integer (sector number) followed by the actual data. 
      The sector number and the data are separated by a colon (`:`).

    Output :
    - print the correctly ordered array (not just printing in order, the array should also be in order)

    Example:

    Input:
    5
    {“3:Memory”, “1:This”, “4:Sector”, “2:is”, “5:a”}

    Output:
    This is a Memory Sector

*/


// WRITE YOUR CODE HERE