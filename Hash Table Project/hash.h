#include <iostream>
#include <string>
#include <cmath>
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

struct Node {
    
    string data;
    Node* next;
    
    Node(string input) {
        data = input;
        next = NULL;
    }
};

int hash_function(string text, int num_of_slots);
void insert(Node** my_hash_table, string text, int num_of_slots);
void print5Slots(Node** my_hash_table);
void printSlotLengths(Node** my_hash_table, int table_size);
float standardDeviation(Node** my_hash_table, int num_of_elements, int table_size);

