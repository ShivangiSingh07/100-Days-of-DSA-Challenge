/*
  A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
So, 'c' → 'a' → 'b' is a valid ordering.
Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
Constraints:
1 ≤ words.length ≤ 500
1 ≤ words[i].length ≤ 100
words[i] consists only of lowercase English letters.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 26   // English lowercase letters

// Queue for BFS (Kahn’s Algorithm)
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

bool isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int val) {
    q->data[q->rear++] = val;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

// Function to find alien dictionary order
char* alienOrder(char** words, int wordsSize) {
    int indegree[MAX] = {0};
    bool present[MAX] = {false};
    int adj[MAX][MAX] = {0}; // adjacency matrix

    // Mark all characters present
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = true;
        }
    }

    // Build graph
    for (int i = 0; i < wordsSize - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i+1];
        int len1 = strlen(w1), len2 = strlen(w2);
        int minLen = len1 < len2 ? len1 : len2;

        bool foundDiff = false;
        for (int j = 0; j < minLen; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';
                if (!adj[u][v]) {
                    adj[u][v] = 1;
                    indegree[v]++;
                }
                foundDiff = true;
                break;
            }
        }
        // Invalid case: prefix conflict (e.g., "abcd" before "ab")
        if (!foundDiff && len1 > len2) {
            return "";
        }
    }

    // Topological sort (Kahn’s Algorithm)
    Queue q;
    initQueue(&q);
    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    char *result = (char*)malloc(MAX+1);
    int idx = 0;

    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        result[idx++] = (char)(u + 'a');
        for (int v = 0; v < MAX; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(&q, v);
                }
            }
        }
    }

    result[idx] = '\0';

    // If not all present letters are included → cycle detected
    int countPresent = 0;
    for (int i = 0; i < MAX; i++) {
        if (present[i]) countPresent++;
    }
    if (idx != countPresent) {
        return "";
    }

    return result;
}

// Driver code
int main() {
    char* words1[] = {"baa", "abcd", "abca", "cab", "cad"};
    char* order1 = alienOrder(words1, 5);
    printf("%s\n", strlen(order1) ? "true" : "false");

    char* words2[] = {"caa", "aaa", "aab"};
    char* order2 = alienOrder(words2, 3);
    printf("%s\n", strlen(order2) ? "true" : "false");

    char* words3[] = {"ab", "cd", "ef", "ad"};
    char* order3 = alienOrder(words3, 4);
    printf("%s\n", strlen(order3) ? "true" : "false");

    return 0;
}
