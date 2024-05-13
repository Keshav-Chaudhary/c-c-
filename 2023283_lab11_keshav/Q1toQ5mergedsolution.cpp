#include <iostream>
#include <vector>

using namespace std;

/* an hash function for demonstration */
int hashFunction(int key, int size) {
    return key % size;
}

// making hash function for double hashing
int hashFunction2(int key, int size) {
    return 7 - (key % 7);  // Just an example, can be any independent hash function
}

/* Define a struct for key-value pairs */
struct KeyValue {
    int key;
    int value;
};

class Hashtable {
private:
    vector<pair<int, int>> table; // The hashtable using vectors for simplicity
    int size;

public:
    Hashtable(int size) : size(size) {
        table.resize(size, {-1, -1}); // Initialize all slots with (-1, -1) indicating empty
    }

    // [2 points] given in question Insertion Operation
    void insert(int key, int value) {
        int index = key % size;
        while (table[index].first != -1) {
            index = (index + 1) % size; // Linear probing
        }
        table[index] = {key, value};
    }

    // [2 points] given as in question Deletion Operation
    void remove(int key) {
        int index = key % size;
        while (table[index].first != key && table[index].first != -1) {
            index = (index + 1) % size; // Linear probing
        }
        if (table[index].first == key) {
            table[index] = {-1, -1}; // Mark as deleted
        }
    }

    // [2 points] Search Operation given 
    int search(int key) {
        int index = key % size;
        while (table[index].first != key && table[index].first != -1) {
            index = (index + 1) % size; // Linear probing
        }
        if (table[index].first == key) {
            return table[index].second; // Return /print/the corresponding value
        }
        return -1; // Key not found
    }
};

int main() {
    // Create a hashtable with size 10 using the example for the execution 
    Hashtable ht(10);

    // Insert key-value pairs
    ht.insert(5, 50);
    ht.insert(15, 150);
    ht.insert(25, 250);
    ht.insert(35, 350);
    ht.insert(45, 450);

    // Search for keys and print results
    cout << "Search Result: Key 35 - Value " << ht.search(35) << endl;
    cout << "Search Rslt: Key 37 - Value " << ht.search(37) << endl; // Not inserted, should return -1

    // Remove a key-value pair and search again
    ht.remove(15);
    cout << "Search Rslt After Removal: Key 15 - Value " << ht.search(15) << endl; // Removed, should return -1

    return 0;
}
