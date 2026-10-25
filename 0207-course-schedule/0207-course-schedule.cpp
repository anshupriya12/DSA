class Solution {
public:
    bool dfsCycleFound(int node, vector<int>& visited, vector<vector<int>>& adj) {
        visited[node] = 1;

        for (int i = 0; i < adj[node].size(); i++) {
            int neighbour = adj[node][i];

            if (visited[neighbour] == 1) {
                return true; //cycle exist
            }
            if (visited[neighbour] == 0) {
                if (dfsCycleFound(neighbour, visited, adj) == true) {
                    return true;
                }
            }
        }

        visited[node] = 2;
        return false; //cycle not found
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //first create a adjacency list

        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {

            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v); 
        }

        for (int i = 0; i < adj.size(); i++) {
            if (visited[i] == 0) {
                if (dfsCycleFound(i, visited, adj) == true) {
                    return false;
                }
            }
        }

        return true;
    }
};