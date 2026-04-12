/*
Problem Statement:
Implement a hash table using quadratic probing with formula:
h(k, i) = (h(k) + i*i) % m

Input Format:
Same as previous.

Output Format:
Result of SEARCH operations.

Sample Input:
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output:
FOUND
NOT FOUND

Explanation:
Collisions resolved using i² jumps.
*/

#include <stdio.h>
#include <string.h>

#define EMPTY -1

int m; // size of hash table
int table[1000]; // hash table array

// Basic hash function
int hash(int key) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key) {
    int h = hash(key);
    for (int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if (table[pos] == EMPTY) {
            table[pos] = key;
            return;
        }
    }
}

// Search using quadratic probing
int search(int key) {
    int h = hash(key);
    for (int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if (table[pos] == EMPTY) {
            return 0; // not found
        }
        if (table[pos] == key) {
            return 1; // found
        }
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &m); // size of hash table
    scanf("%d", &n); // number of operations

    // initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;
    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }
    return 0;
}
