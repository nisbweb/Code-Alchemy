/*
    Due to corruption, foreign key relationships between tables have been broken. 
    You need to restore valid relationships by removing or fixing records that violate foreign key constraints.

    Input Format:
    Two tables represented as lists of objects:
    parent_table: The main table with primary keys.
    primary key: primary key of parent table, foriengn key in child table.
    child_table: The dependent table with foreign keys referencing the parent table.

    Output Format:
    A corrected child_table where all foreign key violations have been removed or fixed.

    Example
    Input:

        parent_table: {
            {"parent_id": 1, "data": "parent_data_1"},
            {"parent_id": 2, "data": "parent_data_2"},
            {"parent_id": 3, "data": "parent_data_3"}
        },
        primarykey: parent_id,
        child_table: {
            {"child_id": 101, "parent_id": 1, "data": "child_data_1"},
            {"child_id": 102, "parent_id": 2, "data": "child_data_2"},
            {"child_id": 103, "parent_id": 4, "data": "child_data_3"}  // Invalid parent_id
        }


    Output:
        {
        {"child_id": 101, "parent_id": 1, "data": "child_data_1"},
        {"child_id": 102, "parent_id": 2, "data": "child_data_2"}
    }

*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Define the structure for Parent and Child tables
struct Parent {
    int parent_id;
    string data;
};

struct Child {
    int child_id;
    int parent_id;
    string data;
};

// Function to restore valid relationships
vector<Child> restoreChildTable(const vector<Parent>& parent_table, const vector<Child>& child_table) {
    // Store valid parent ids in a set
    unordered_set<int> valid_parent_ids;
    for (const auto& parent : parent_table) {
        valid_parent_ids.insert(parent.parent_id);
    }

    // Filter out invalid children
    vector<Child> corrected_child_table;
    for (const auto& child : child_table) {
        if (valid_parent_ids.find(child.parent_id) != valid_parent_ids.end()) {
            corrected_child_table.push_back(child);
        }
    }
    
    return corrected_child_table;
}

int main() {
    int parent_size, child_size;

    // Input the number of entries in the parent table
    cout << "Enter the number of entries in the parent table: ";
    cin >> parent_size;

    vector<Parent> parent_table(parent_size);
    
    // Input for parent table
    cout << "Enter parent table data (parent_id and data): " << endl;
    for (int i = 0; i < parent_size; ++i) {
        cout << "Parent " << i + 1 << ": ";
        cin >> parent_table[i].parent_id >> parent_table[i].data;
    }

    // Input the number of entries in the child table
    cout << "Enter the number of entries in the child table: ";
    cin >> child_size;

    vector<Child> child_table(child_size);

    // Input for child table
    cout << "Enter child table data (child_id, parent_id, and data): " << endl;
    for (int i = 0; i < child_size; ++i) {
        cout << "Child " << i + 1 << ": ";
        cin >> child_table[i].child_id >> child_table[i].parent_id >> child_table[i].data;
    }

    // Restore valid relationships
    vector<Child> corrected_child_table = restoreChildTable(parent_table, child_table);

    // Output the corrected child table
    cout << "Corrected Child Table:" << endl;
    for (const auto& child : corrected_child_table) {
        cout << "{child_id: " << child.child_id
             << ", parent_id: " << child.parent_id
             << ", data: " << child.data << "}" << endl;
    }

    return 0;
}
