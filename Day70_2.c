/*
LeetCode 787. Cheapest Flights Within K Stops
------------------------------------------------
There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] 
indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, 
return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1.

Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700

Example 2:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200

Example 3:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500

Constraints:
- 2 <= n <= 100
- 0 <= flights.length <= (n * (n - 1) / 2)
- flights[i].length == 3
- 0 <= fromi, toi < n
- fromi != toi
- 1 <= pricei <= 10^4
- There will not be any multiple flights between two cities.
- 0 <= src, dst, k < n
- src != dst
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    int INF = INT_MAX / 2; // avoid overflow
    int* dist = (int*)malloc(n * sizeof(int));
    int* temp = (int*)malloc(n * sizeof(int));

    // initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // relax edges up to k+1 times
    for (int i = 0; i <= k; i++) {
        // copy current distances
        for (int j = 0; j < n; j++) {
            temp[j] = dist[j];
        }
        // relax all edges
        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];
            if (dist[u] != INF && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }
        // update distances
        for (int j = 0; j < n; j++) {
            dist[j] = temp[j];
        }
    }

    int ans = dist[dst];
    free(dist);
    free(temp);

    return ans == INF ? -1 : ans;
}
