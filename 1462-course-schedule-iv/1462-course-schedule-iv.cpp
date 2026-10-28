class Solution {
public:
    bool dfsAnswer(vector<vector<int>>& adj, int source, int dest, vector<bool>& visited) {

        if (source == dest) return true; //reached to destination
        visited[source] = true;

        bool isReachable = false;

        for (int i = 0; i < adj[source].size(); i++) {
            int neighbour = adj[source][i];

            if (visited[neighbour]==false) {
                isReachable = isReachable || dfsAnswer(adj, neighbour, dest, visited);
            }
        }

        return isReachable;

    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //make a graph using prerequisite array 

        vector<vector<int>> adj(numCourses);

        for (auto &edge: prerequisites) {
            int u = edge[0];
            int v = edge[1];

            //given 
            //a--->b

            adj[u].push_back(v);
        }

        int n = queries.size();
        vector<bool> results(n);

        for (int i = 0; i < n; i++) {
            //approach: DFS for every query 
            int u = queries[i][0];//source
            int v = queries[i][1]; //dest.

            vector<bool> visited(numCourses, false);

            results[i] = dfsAnswer(adj, u, v, visited);

        }

        return results;
    }
};