/*
Problem Statement:
Given a 2D matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j.
Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once
and then at the end come back to city 0 at minimum cost.

Constraints:
1 ≤ cost.size() ≤ 15
0 ≤ cost[i][j] ≤ 10^4
*/

#include <stdio.h>
#include <limits.h>

#define MAXN 15
#define INF INT_MAX

int n;
int cost[MAXN][MAXN];
int dp[1 << MAXN][MAXN]; // DP table: state = visited cities, last city

// Recursive function with memoization
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        // All cities visited, return cost to go back to city 0
        return cost[pos][0];
    }
    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city))) { // if city not visited
            int newAns = cost[pos][city] + tsp(mask | (1 << city), city);
            if (newAns < ans) ans = newAns;
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize DP table
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    // Start from city 0, with mask = 1 (only city 0 visited)
    int answer = tsp(1, 0);
    printf("%d\n", answer);

    return 0;
}
