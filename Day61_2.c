/*
There are n cities. Some of them are connected, while some are not.
If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c. 
A province is a group of directly or indirectly connected cities and no other cities outside of the group. 
You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
Return the total number of provinces.
*/

#include <stdio.h>

void dfs(int** isConnected, int n, int* visited, int i) {
    visited[i] = 1;
    for (int j = 0; j < n; j++) {
        if (isConnected[i][j] == 1 && !visited[j]) {
            dfs(isConnected, n, visited, j);
        }
    }
}

int findCircleNum(int** isConnected, int n) {
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, n, visited, i);
            count++;
        }
    }
    return count;
}

int main() {
    int n1 = 3;
    int arr1[3][3] = {{1,1,0},{1,1,0},{0,0,1}};
    int* isConnected1[3];
    for (int i = 0; i < n1; i++) isConnected1[i] = arr1[i];
    printf("%d\n", findCircleNum(isConnected1, n1));

    int n2 = 3;
    int arr2[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    int* isConnected2[3];
    for (int i = 0; i < n2; i++) isConnected2[i] = arr2[i];
    printf("%d\n", findCircleNum(isConnected2, n2));

    return 0;
}
