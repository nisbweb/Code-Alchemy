/*
    The network’s TCP timeout and retransmission mechanisms are failing, leading to data packets being lost or delayed. 
    To fix this, you need to implement a min-heap to manage TCP timers and prioritize packet retransmissions. 
    The system should ensure that the packet with the earliest timeout is retransmitted first, and packets are retransmitted only when they time out or when an acknowledgment (ACK) for that packet has not been received.

    Packets are represented by their IDs and timeout values (in milliseconds). Lower timeout values mean the packet should be retransmitted sooner. 
    Your task is to use a min-heap to keep track of these timeouts and retransmit packets efficiently.

    Input:
    A list of tuples, where each tuple represents a packet ID and its timeout in milliseconds.
    A list of packet IDs that have been acknowledged (no need to retransmit).
    The number of retransmissions to perform.

    Output:
    A list of packet IDs in the order they should be retransmitted based on the shortest timeout.

    Example
    Input:
    packets = [(1, 500), (2, 300), (3, 400), (4, 600), (5, 200)]
    acknowledged = [2, 5]
    num_retransmissions = 2

    Output:
    [3, 1]
*/

// WRITE YOUR CODE HERE