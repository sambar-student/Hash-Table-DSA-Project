#include <iostream>
#include <string>
#include <cmath>
#include "hash.h"

using namespace std;



int hash_function(string text, int num_of_slots) {
    // Implement your own hash function here
    int sum = 0;
    for (int i = 0; i < (int)text.size(); ++i) {
        sum = sum + (int)(text[i]);
    }
    return (sum % num_of_slots);
    // In the hash function, all of the ASCII values of each character is added up. Then, I do sum % num_of_slots. This will give me a value between 0 and (num_of_slots - 1)
}
void insert(Node** my_hash_table, string text, int num_of_slots) {

    // First, the hash function is called to generate the slot that the string will go into
    int slot = hash_function(text,num_of_slots);

    Node* newNode = new Node(text);
    // Then, I set this newNode's next pointer to the first value in the linked list. 
    newNode->next = my_hash_table[slot];
    // Now that newNode is the beginning of the list, newNode is then placed in the slot in the hash table so that it is now the head.
    my_hash_table[slot] = newNode;
}

void print5Slots(Node** my_hash_table) {
    // Loop iterates through first 5 slots of hash_table array
    for (int i = 0; i <= 4; i++) {
        cout << "Slot " << i << ": ";
        // Iterating variable is set as the start to the linked list in every slot.
        Node* firstNode = my_hash_table[i];
        while (firstNode) {
            // Use firstNode to iterate through each node and print the each value. Then, firstNode goes to next node till the end of the list.
            cout << firstNode->data << " ";
            firstNode = firstNode->next;
        }
        cout << endl;
    }
}
void printSlotLengths(Node** my_hash_table, int table_size) {
    // Loop iterates through each slot of the hash_table 
    for (int i = 0; i < table_size; i++) {
        int slot_length = 0;
        cout << "Slot " << i << ": ";
        // Use iterator variable to go through the linked list in each slot
        Node* iterator = my_hash_table[i];
        while (iterator) {
            // This uses iterator to iterate from start to finish. At each node, slot_length is incremented
            slot_length = slot_length + 1;
            iterator = iterator->next;
            
        }
        // slot_length is then printed when end of list is reached
        cout << slot_length << endl;
    }
}

float standardDeviation(Node** my_hash_table, int num_of_elements, int table_size) {
    // In this case, mean is average number of elements at each slot. We can find this by doing n/k
    float mean = (float)(num_of_elements)/(table_size);
    float sum = 0;
    for (int i = 0; i < table_size; i++) {
        // outer loop iterates from through each slot
        int length = 0;
        Node* current = my_hash_table[i];
        // Inner loop iterates through each element in each linked list. It also keeps track of how many elements are in each list.
        while (current) {
            length++;
            current = current->next;
        }
        // This performs calculation of each (xi - mean)^2, where xi is the length of each slot and mean is average length per slot.
        // This is then added to the sum for summation
        sum = sum + (length - mean)*(length - mean);
    }
    // Final calculations for standard deviation
    sum = sum/table_size;
    return sqrt(sum);
}