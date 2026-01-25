/*
CSE 310 Hash Function DIY Contest
Instructor: "YZ" Yezhou Yang
Your name(s): Saikrishna Vinapamula
Your team alias: Team Soccer
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"

//#include "hash.cpp"
using namespace std;

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now
    // This creates an array of linked list with the size of what is specified in the input file
    Node** my_hash_table = new Node*[k];
    // For every element in texts array, the loop inserts a node with that value into the hash_table
    for (int i = 0; i < n; ++i) {
        insert(my_hash_table, texts[i], k);
        
    }
    // Below, the three methods are called that display the appropriate outputs
    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    print5Slots(my_hash_table);
    cout << "==== Printing the slot lengths ====" << endl;
    printSlotLengths(my_hash_table, k);
    cout << "==== Printing the standard variance =====" << endl;
    cout << standardDeviation(my_hash_table, n, k) << endl;
    /* This is the code for deleting hash table*/
    for (int i = 0; i < k; i++) {
        Node* current = my_hash_table[i];
        // The inner loop deletes each individual node within each slot
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;    
        }

    }
    delete[] my_hash_table;
    return 0;
}