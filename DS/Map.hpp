#ifndef MAP_HPP
#define MAP_HPP

#include <stdexcept>
#include <functional>


template <typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Node* next;

        Node(const K& key, const V& value) : key(key), value(value), next(nullptr) {}
    };

    Node** table;
    int capacity;
    int size;

    int hash(const K& key) const {
        return std::hash<K>{}(key) % capacity;
    }

public:
    // Constructor: Initializes the table with the specified capacity
    Map(int capacity = 10) : capacity(capacity), size(0) {
        table = new Node*[capacity]{};  // Initialize all elements to nullptr
    }

    // Destructor: Cleans up allocated memory
    ~Map() {
        for (int i = 0; i < capacity; ++i) {
            Node* current = table[i];
            while (current) {
                Node* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
        delete[] table;
    }

    // Insert a key-value pair into the map
    void insert(const K& key, const V& value) {
        int index = hash(key);
        Node* current = table[index];

        // Check if the key already exists, update its value 
        while (current) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        // If key doesn't exist create a new node and insert it at the beginning of the chain
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
        ++size;
    }

    // Find a key and return a pointer to the associated value
    V* find(const K& key) const {  
        int index = hash(key);
        Node* current = table[index];
        while (current) {
            if (current->key == key) {
                return &current->value;
            }
            current = current->next;
        }
        return nullptr;  // Return nullptr if the key is not found
    }

    int getSize() const {
        return size;
    }
};

#endif
