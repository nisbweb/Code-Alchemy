/*
    The operating system is facing security vulnerabilities due to improper transitions between kernel mode and user mode. Kernel mode grants elevated privileges to processes, while user mode restricts access to critical system resources. Improper transitions could lead to unauthorized access, potentially compromising system security.

    Your task is to implement a system that securely manages transitions between kernel mode and user mode using bit manipulation. You will be provided with a series of system call requests, each represented by an integer that indicates the requested mode. Your goal is to ensure only legitimate transitions occur based on the current mode and the requested mode.

    The system should:
    - Start in user mode.
    - Only allow transitions from user mode to kernel mode if the system call request is valid.
    - Revert back to user mode after the completion of the kernel operation.
    - Ignore any invalid transitions that compromise security.

    Input:
    An integer n, representing the number of system call requests.
    A list of n integers requests, where each integer represents a mode change request:
    1 represents a request to enter kernel mode.
    0 represents a request to return to user mode.

    Output:
    An integer representing the total number of valid mode transitions.
    A binary integer representing the final mode:
    0 for user mode.
    1 for kernel mode.

    Execution Rules:
    -The system starts in user mode (0).
    -A transition from user mode (0) to kernel mode (1) is valid only if the request is 1.
    -Once in kernel mode (1), the system can only return to user mode (0) if the request is 0.
    -Any requests that violate these rules should be ignored.
    -Track the total number of valid transitions.

    Example
    n = 5
    requests = [1, 0, 1, 0, 0]

    Output:
    Valid transitions: 4
    Final mode: 0

    Explanation:
    - The system starts in user mode (0).
    - The first request is 1 (switch to kernel mode), which is valid, so the system enters kernel mode (1).
    - The second request is 0 (return to user mode), which is valid, so the system returns to user mode (0).
    - The third request is 1 (switch to kernel mode), which is valid, so the system enters kernel mode (1).
    - The fourth request is 0 (return to user mode), which is valid, so the system returns to user mode (0).
    - The fifth request is 0, but since the system is already in user mode, this request is ignored.
    - Total valid transitions: 4, final mode: user mode (0).

*/

// WRITE YOUR CODE HERE