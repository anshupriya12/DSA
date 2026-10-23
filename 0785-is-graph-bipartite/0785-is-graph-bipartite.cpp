
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int curr,
             vector<int>& color, int currColor) {

        color[curr] = currColor;

        for (int i = 0; i < graph[curr].size(); i++) {
            int v = graph[curr][i];

            if (color[v] == -1) {
                int oppositeColor;

                if (currColor == 0) {
                    oppositeColor = 1;
                }
                else {
                    oppositeColor = 0;
                }

                if (dfs(graph, v, color, oppositeColor) == false) {
                    return false;
                }
            }

            if (color[v] != -1) {
                if (color[v] == currColor) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(graph, i, color, 0) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};
