#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        const int MAXV = 501;
        vector<bool> present(MAXV, false);
        vector<unordered_set<int>> adj(MAXV);

        for (auto& p : pairs) {
            int x = p[0], y = p[1];
            present[x] = present[y] = true;
            adj[x].insert(y);
            adj[y].insert(x);
        }

        vector<int> nodes;
        for (int i = 1; i < MAXV; i++) {
            if (present[i]) nodes.push_back(i);
        }
        int n = nodes.size();
        if (n == 0) return 0;

        vector<int> deg(MAXV, 0);
        for (int u : nodes) deg[u] = adj[u].size();

        int root = -1;
        for (int u : nodes) {
            if (deg[u] == n - 1) {
                root = u;
                break;
            }
        }
        if (root == -1) return 0;

        bool multiple = false;

        for (int u : nodes) {
            if (u == root) continue;

            int parent = -1;
            int best_deg = INT_MAX;

            for (int v : adj[u]) {
                if (deg[v] >= deg[u] && deg[v] < best_deg) {
                    parent = v;
                    best_deg = deg[v];
                }
            }

            if (parent == -1) return 0;

            for (int v : adj[u]) {
                if (v == parent) continue;
                if (!adj[parent].count(v)) {
                    return 0;
                }
            }

            if (deg[parent] == deg[u])
                multiple = true;
        }

        return multiple ? 2 : 1;
    }
};
