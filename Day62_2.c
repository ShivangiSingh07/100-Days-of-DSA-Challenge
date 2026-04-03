// Problem: Keys and Rooms (LeetCode 841)
// Input: rooms[i] contains keys to other rooms
// Output: true if all rooms can be visited, false otherwise

#include <stdbool.h>

void dfs(int** rooms, int roomsSize, int* roomsColSize, int room, bool* visited) {
    visited[room] = true;
    for (int i = 0; i < roomsColSize[room]; i++) {
        int nextRoom = rooms[room][i];
        if (!visited[nextRoom]) {
            dfs(rooms, roomsSize, roomsColSize, nextRoom, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];
    for (int i = 0; i < roomsSize; i++) visited[i] = false;

    dfs(rooms, roomsSize, roomsColSize, 0, visited);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) return false;
    }
    return true;
}
