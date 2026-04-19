/*
Problem Statement:
Given an undirected connected graph with V vertices and adjacency list adj.
Find all the vertices removing which disconnects the graph into 2 or more components.
Return them in sorted order. If none, return {-1}.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc,
             vector<int>& low, vector<int>& ap, int& time) {
        disc[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;
            if (disc[v] == -1) {
                children++;
                dfs(v, u, adj, disc, low, ap, time);
                low[u] = min(low[u], low[v]);

                if (parent != -1 && low[v] >= disc[u])
                    ap[u] = 1;
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (parent == -1 && children > 1)
            ap[u] = 1;
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, -1), low(V, -1), ap(V, 0);
        int time = 0;

        for (int i = 0; i < V; i++) {
            if (disc[i] == -1)
                dfs(i, -1, adj, disc, low, ap, time);
        }

        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (ap[i]) res.push_back(i);
        }
        if (res.empty()) return {-1};
        return res;
    }
};
