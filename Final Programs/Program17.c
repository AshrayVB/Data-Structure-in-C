//Given a File of N employee records with a set K of Keys (4-digit) which uniquely determine the records in file F. Assume that file F is maintained in memory by a Hash
//Table (HT) of m memory locations with L as the set of memory addresses (2-digit) of locations in HT. Let the keys in K and addresses in L are Integers. Design and develop
//a Program in C that uses Hash function H: K →L as H(K)=K mod m (remainder method) and implement hashing technique to map a given key K to the address space
//L. Resolve the collision (if any) using linear probing.

#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100
#define MAX_MEMORY_LOCATIONS 10

struct Employee {
    int key;
    char name[50];
    // Add other employee details as needed
};

struct HashTable {
    struct Employee* table[MAX_MEMORY_LOCATIONS];
};

// Function to create an employee record
struct Employee* createEmployee(int key, const char* name) {
    struct Employee* employee = (struct Employee*)malloc(sizeof(struct Employee));
    if (employee == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    employee->key = key;
    strcpy(employee->name, name);
    return employee;
}

// Function to initialize the hash table
void initializeHashTable(struct HashTable* hashTable) {
    for (int i = 0; i < MAX_MEMORY_LOCATIONS; i++) {
        hashTable->table[i] = NULL;
    }
}

// Hash function H(K) = K mod m (remainder method)
int hashFunction(int key, int m) {
    return key % m;
}

// Function to insert an employee record into the hash table
void insert(struct HashTable* hashTable, int key, const char* name) {
    int index = hashFunction(key, MAX_MEMORY_LOCATIONS);
    while (hashTable->table[index] != NULL) {
        index = (index + 1) % MAX_MEMORY_LOCATIONS; // Linear probing
    }
    hashTable->table[index] = createEmployee(key, name);
}

// Function to display the contents of the hash table
void displayHashTable(struct HashTable* hashTable) {
    printf("\nHash Table:\n");
    printf("Address\tKey\tName\n");
    for (int i = 0; i < MAX_MEMORY_LOCATIONS; i++) {
        if (hashTable->table[i] != NULL) {
            printf("%d\t%d\t%s\n", i, hashTable->table[i]->key, hashTable->table[i]->name);
        } else {
            printf("%d\t---\t---\n", i);
        }
    }
}

int main() {
    int n; // Number of employee records
    printf("Enter the number of employee records: ");
    scanf("%d", &n);
    struct HashTable hashTable;
    initializeHashTable(&hashTable);
    printf("Enter the employee records (key name):\n");
    for (int i = 0; i < n; i++) {
        int key;
        char name[50];
        scanf("%d %s", &key, name);
        insert(&hashTable, key, name);
    }
    displayHashTable(&hashTable);
    return 0;
}