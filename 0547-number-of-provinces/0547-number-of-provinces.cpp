class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int node, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbour = 0; neighbour < isConnected.size(); neighbour++) {
            if (isConnected[node][neighbour] == 1 && !visited[neighbour]) {
                dfs(isConnected, neighbour, visited);

            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(isConnected, i, visited);
                count++;
            }
        }

        return count;
    }
};