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