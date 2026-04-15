/*
Problem Statement:
Given an array of candidate names where each name represents a vote cast for that candidate, 
determine the candidate who received the maximum number of votes. 
In case of a tie, return the lexicographically smallest candidate name.

Input Format:
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format:
Print the name of the winning candidate followed by the number of votes received.

Sample Input:
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output:
john 4
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store candidate name and vote count
typedef struct {
    char name[100];
    int count;
} Candidate;

// Function to compare two candidates for qsort
int compare(const void *a, const void *b) {
    Candidate *c1 = (Candidate *)a;
    Candidate *c2 = (Candidate *)b;
    // Sort by name lexicographically
    return strcmp(c1->name, c2->name);
}

int main() {
    int n;
    scanf("%d", &n);

    char names[n][100];
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Sort names lexicographically
    qsort(names, n, sizeof(names[0]), (int (*)(const void*, const void*))strcmp);

    Candidate candidates[n];
    int candidateCount = 0;

    // Count votes
    for (int i = 0; i < n; i++) {
        if (candidateCount == 0 || strcmp(candidates[candidateCount - 1].name, names[i]) != 0) {
            strcpy(candidates[candidateCount].name, names[i]);
            candidates[candidateCount].count = 1;
            candidateCount++;
        } else {
            candidates[candidateCount - 1].count++;
        }
    }

    // Find candidate with max votes
    char winner[100];
    int maxVotes = 0;
    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].count > maxVotes) {
            maxVotes = candidates[i].count;
            strcpy(winner, candidates[i].name);
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
