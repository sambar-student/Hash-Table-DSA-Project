Team Name: Team Soccer
Team Member: Saikrishna Vinapamula
ASU ID: 1226011178

hash.cpp class:
struct Node: This defines the Node that will store the string inputs. It contains a string data, a next node pointer, and a constructor.
hash_function: This takes in the input string and total number of slots, and it calculates the slot that the input should go into.
insert: This inserts a node into the hash table given the hash table, input string, and number of slots in table. It inserts at the beginning of the linked list.
print5Slots: This uses a loop that runs four times. Each time, it iterates through the linked list in each slot. It then prints the information in each Node.
printSlotLengths: This uses two nested loops. The outer loop iterates through each slot in the hash table. The inner loop iterates through each linked list. When visiting each node of the linked list until the end, a counter is incremented. The counter is then printed out. This is done for each slot in the hash table. 
standardDeviation: This method takes the hash table, number of elements in total, and the number of slots in the table as input. The mean is calculated by dividing the number of elements by the number of slots. Then, we iterate through each slot and within each slot. Within each slot, we find the length of the linked list, and we do (xi - mean)^2. We then add this to a sum variable for the summation. At the end of this, we divide sum by the number of slots. Then, take the square root of this value.

Hash Table: To create the hash table, a node is used to store each string. A Node double pointer is used to refer to an array of linked lists. The array of Node pointers is created dynamically using "new Node*[k]".

main.cpp:
First, a loop is used to insert every string into the hash table. Then, print5Slots(), printSlotLengths(), and standardDeviation() are used to create the outputs for each task. At the end, two nested loops are used to delete each individual node and then the entire hash table.