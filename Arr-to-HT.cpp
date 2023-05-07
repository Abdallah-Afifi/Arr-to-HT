#include <iostream>
#include <vector>
#include <list>

const int TABLE_SIZE = 10;  // Size of the hash table

// Node structure for chaining
struct Node {
    int value;
    Node* next;
};

// Hash Table class
class HashTable {
private:
    std::vector<std::list<Node*>> table;  // Vector of linked lists

public:
    HashTable() {
        table.resize(TABLE_SIZE);  // Resize the vector to the specified table size
    }

    // Hash function to map the key to an index
    int hash(int key) {
        return key % TABLE_SIZE;
    }

    // Insert a value into the hash table
    void insert(int value) {
        int index = hash(value);

        // Create a new node
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;

        // Insert the node at the appropriate index
        table[index].push_back(newNode);
    }

    // Print the hash table
    void printTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            std::cout << "Index " << i << ": ";
            for (Node* node : table[i]) {
                std::cout << node->value << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int arr[] = {1, 4, 7, 1, 5, 2, 4, 1, 3, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    HashTable hashTable;

    // Insert each element of the array into the hash table
    for (int i = 0; i < arrSize; i++) {
        hashTable.insert(arr[i]);
    }

    // Print the hash table
    hashTable.printTable();

    return 0;
}
