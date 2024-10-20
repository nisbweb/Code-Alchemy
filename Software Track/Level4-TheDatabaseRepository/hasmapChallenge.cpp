/*
    The Database Repository is corrupted, causing issues with data retrieval. To fix this, you need to rebuild the database indices using a hashmap. 
    The goal is to efficiently map keys (representing unique data identifiers) to values (the corresponding data) and remove any inconsistencies, such as duplicated or missing keys.

    You are given a list of key-value pairs representing database entries. Some keys may be duplicated or missing. 
    Your task is to organize this data into a hashmap, ensuring that each key maps to its correct and unique value. If a key appears more than once, retain only the most recent entry.

    Write a function in C++ that takes a 2D vector of key-value pairs and returns a map with unique keys. For any duplicate keys, retain only the value from the latest entry.

    Input:
    A 2D vector where each sub-vector represents a key-value pair:
    vector<vector<string>> entries = {{key1, value1}, {key2, value2}, ..., {keyN, valueN}}
    Here, key represents the data identifier and value represents the corresponding data.

    Output:
    A C++ map<string, string> where each key maps to its corresponding unique value.

    Example:
    Input:
    vector<vector<string>> entries = {
        {"user1", "dataA"},
        {"user2", "dataB"},
        {"user1", "dataC"},
        {"user3", "dataD"},
        {"user2", "dataE"}
    };

    Output:
    {
        {"user1", "dataC"},
        {"user2", "dataE"},
        {"user3", "dataD"}
    }

    Explanation:
    "user1" appeared twice, so the most recent value "dataC" is retained.
    "user2" appeared twice, so the most recent value "dataE" is retained.
    "user3" appeared only once, so "dataD" is retained.
*/

// WRITE YOUR CODE HERE


#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int  main()
{

vector<vector<string>> entries = {
        {"user1", "dataA"},
        {"user2", "dataB"},
        {"user1", "dataC"},
        {"user3", "dataD"},
        {"user2", "dataE"}
    };

    map<string,string>mp;
    for(int i=0;i<entries.size();i++)
    {
          mp[entries[i][0]]=entries[i][1];

        
    }
    for(auto i:mp)
    {
       cout<<i.first<<":"<<i.second<<endl;


    }


    return 0;
}




