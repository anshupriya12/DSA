class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //build the adjacency list
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        dfs(source, adj, visited);

        return visited[destination];
    }
};