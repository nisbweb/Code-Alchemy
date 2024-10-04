/*
    The database transactions are conflicting due to overlapping time intervals, which can cause data to be overwritten. 
    Your task is to implement a function that merges overlapping transactions and ensures data integrity by consolidating them into non-overlapping intervals.

    Input Format:
    A list of transactions, where each transaction is represented as an object containing:

    transaction_id: (integer) The unique identifier of the transaction.
    start_time: (integer) The start time of the transaction in units.
    end_time: (integer) The end time of the transaction in units.

    Output Format:
    A list of merged transactions, each represented as an object with:

    transaction_id: (integer) The transaction ID of the merged transaction.
    start_time: (integer) The start time of the merged interval.
    end_time: (integer) The end time of the merged interval.


    Example
    Input
    [
        {"transaction_id": 1, "start_time": 0, "end_time": 3},
        {"transaction_id": 2, "start_time": 2, "end_time": 4},
        {"transaction_id": 3, "start_time": 5, "end_time": 7},
        {"transaction_id": 4, "start_time": 6, "end_time": 8},
        {"transaction_id": 5, "start_time": 8, "end_time": 10}
    ]

    Output
    [
        {"transaction_id": 1, "start_time": 0, "end_time": 4},
        {"transaction_id": 3, "start_time": 5, "end_time": 8},
        {"transaction_id": 5, "start_time": 8, "end_time": 10}
    ]

*/

// WRITE YOUR CODE HERE