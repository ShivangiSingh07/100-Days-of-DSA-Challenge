/*
LeetCode 210. Course Schedule II

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must
take course bi first if you want to take course ai.

For example, the pair [0, 1] indicates that to take course 0 you have to first take course 1.

Return the ordering of courses you should take to finish all courses. If there are many valid
answers, return any of them. If it is impossible to finish all courses, return an empty array.

Examples:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3] or [0,1,2,3]

Input: numCourses = 1, prerequisites = []
Output: [0]

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* result;       // stores topological order
int idx;           // index for result array
int* visited;      // 0 = unvisited, 1 = visiting, 2 = visited
int cycle;         // flag for cycle detection

// adjacency list
typedef struct Node {
    int course;
    struct Node* next;
} Node;

Node** graph;

// add edge u -> v
void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->course = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

// DFS
void dfs(int v) {
    if (cycle) return;
    visited[v] = 1; // visiting
    Node* temp = graph[v];
    while (temp) {
        if (visited[temp->course] == 0) {
            dfs(temp->course);
        } else if (visited[temp->course] == 1) {
            cycle = 1; // cycle detected
            return;
        }
        temp = temp->next;
    }
    visited[v] = 2; // visited
    result[idx--] = v; // add to result in reverse order
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize,
               int* prerequisitesColSize, int* returnSize) {
    // initialize
    graph = (Node**)malloc(numCourses * sizeof(Node*));
    visited = (int*)malloc(numCourses * sizeof(int));
    result = (int*)malloc(numCourses * sizeof(int));
    for (int i = 0; i < numCourses; i++) {
        graph[i] = NULL;
        visited[i] = 0;
    }

    // build graph
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        addEdge(b, a); // b -> a
    }

    idx = numCourses - 1;
    cycle = 0;

    // run DFS
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }

    if (cycle) {
        *returnSize = 0;
        return (int*)malloc(0); // empty array
    }

    *returnSize = numCourses;
    return result;
}
