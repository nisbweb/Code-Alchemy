/*
    In a system with multiple transactions, each transaction is requesting and holding certain resources. 
    Your task is to detect whether a deadlock is present based on these transactions and the resources involved.

    Input Format:
    A list of transactions, where each transaction is represented as an array containing:
    - transaction_id: (integer) The unique identifier of the transaction.
    - resources_requested: (string) The resource that the transaction is requesting.
    - resources_held: (string) The resource currently held by the transaction.

    Output Format:
    A boolean value:
    true if a deadlock is present.
    false if no deadlock is detected.

    Example:
    Input
    [
        [1, "B", "A"],  // Transaction 1 requests B but holds A
        [2, "C", "B"],  // Transaction 2 requests C but holds B
        [3, "A", "C"]   // Transaction 3 requests A but holds C
    ]

    Output
    true

    Explanation:
    Transaction 1 holds resource A and requests B.
    Transaction 2 holds resource B and requests C.
    Transaction 3 holds resource C and requests A.
    This creates a circular wait situation (1 → 2 → 3 → 1), meaning no transaction can proceed, which leads to a deadlock. Hence, the output is true.

*/

// WRITE YOUR CODE HERE