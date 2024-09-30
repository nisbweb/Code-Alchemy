/*
    You are responsible for optimizing the memory management of an operating system that experiences frequent page faults due to inefficient paging strategies. 
    Your task is to implement an efficient paging algorithm using a heap to prioritize pages based on usage frequency, specifically using the Least Recently Used (LRU) or Least Frequently Used (LFU) strategies.

    You need to manage the pages in memory, handle page faults by swapping in necessary pages, and minimize performance hits.

    Input:
    An integer capacity, representing the maximum number of pages that can be held in memory.
    A list of integers representing page requests, where each integer corresponds to a page number that is accessed.

    Output:
    The total number of page faults encountered during the process.

    Definitions:
    Page fault occurs when a requested page is not found in memory, requiring a page swap to bring it into memory.
    The Least Recently Used (LRU) strategy removes the page that has not been used for the longest time.
    The Least Frequently Used (LFU) strategy removes the page that has the lowest usage frequency.

    Execution Rule:
    If a requested page is already in memory, do nothing.
    If a requested page is not in memory and the capacity is reached, use the chosen strategy (LRU or LFU) to determine which page to remove before adding the new page.

    Example:
    Input:
    capacity = 3
    pages = [1, 2, 3, 1, 4, 2, 3, 4, 5]

    Output:
    6

    Explanation:
    Initially, pages [1, 2, 3] are loaded, causing 3 page faults for the first three requests.
    The next request for page 1 does not cause a fault since it's already in memory.
    The request for page 4 causes a page fault, removing page 3 (assuming LRU), and adding page 4.
    The request for page 2 does not cause a fault.
    The request for page 3 causes a fault, removing page 2 and adding page 3.
    The request for page 4 does not cause a fault.
    Finally, the request for page 5 causes a fault, removing page 1 and adding page 5.
    Total page faults: 6 (for pages 1, 2, 3, 4, 3, and 5).
*/

// WRITE YOUR CODE HERE

