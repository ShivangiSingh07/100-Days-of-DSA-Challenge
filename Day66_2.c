/*
LeetCode 207. Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
take course bi first if you want to take course ai.

Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS helper to detect cycle
bool dfsCycle(int v, int** adj, int* adjSize, bool* visited, bool* recStack) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < adjSize[v]; i++) {
        int u = adj[v][i];
        if (!visited[u] && dfsCycle(u, adj, adjSize, visited, recStack))
            return true;
        else if (recStack[u])
            return true;
    }

    recStack[v] = false;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    // adjacency list
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int)); // worst case
    }

    // build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];
        adj[pre][adjSize[pre]++] = course;
    }

    bool* visited = (bool*)calloc(numCourses, sizeof(bool));
    bool* recStack = (bool*)calloc(numCourses, sizeof(bool));

    // check for cycle
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, adj, adjSize, visited, recStack)) {
                return false; // cycle detected → cannot finish
            }
        }
    }

    return true; // no cycle → can finish
}

// Example driver
int main() {
    int numCourses = 2;
    int prerequisitesSize = 2;
    int prerequisitesColSize[] = {2, 2};

    int prereqData[2][2] = {{1,0}, {0,1}};
    int* prerequisites[2];
    for (int i = 0; i < prerequisitesSize; i++) {
        prerequisites[i] = prereqData[i];
    }

    if (canFinish(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
