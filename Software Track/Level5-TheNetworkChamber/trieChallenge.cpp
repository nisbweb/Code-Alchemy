/*
    The system’s network address directory has become corrupted, making it difficult to search for hostnames or IP addresses. To efficiently manage and autocomplete network addresses, you are tasked with implementing a trie (prefix tree) that stores network hostnames. This trie will allow fast lookup, insertion, and autocompletion of hostnames based on given prefixes.

    Your task is to build the trie and use it to find whether a given hostname exists in the system, and to return possible autocompletions for a given prefix.

    Input:

    A list of hostnames to be inserted into the trie.
    A list of search queries where each query is either a complete hostname or a prefix to be autocompleted.
    Output:

    For each query:
    If it is a full hostname, return whether it exists in the trie.
    If it is a prefix, return all possible hostnames starting with that prefix.

    Example
    Input:
    hostnames = ["node1.network.com", "node2.network.com", "router.main.net", "switch.local.net"]
    queries = ["node", "node1.network.com", "router", "switch.local", "gateway"]

    Output:
    [
    ["node1.network.com", "node2.network.com"], // Autocomplete for "node"
    true,                                       // "node1.network.com" exists
    ["router.main.net"],                        // Autocomplete for "router"
    ["switch.local.net"],                       // Autocomplete for "switch.local"
    false                                       // "gateway" doesn't exist
    ]
*/

// WRITE YOUR CODE HERE