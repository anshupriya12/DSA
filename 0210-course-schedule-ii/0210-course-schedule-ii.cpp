class Solution {
public:
    vector<int> topologicalSort(vector<vector<int>>& adj, int n, vector<int>& indegree) {
        queue<int> que;

        vector<int> result; //keep the topological sort
        int count = 0; //have we visited all the courses

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                result.push_back(i);
                count++;
                que.push(i); //processed by BFS
            }
        }

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (int &v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    result.push_back(v);
                    count++;
                    que.push(v);
                }
            }
        }

        if (count == n) return result;

        return {};
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        //using kahn's algorithm 
        //make graph 
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &vec : prerequisites) {
            int u = vec[0];
            int v = vec[1];

            //{u,v} 
            //v-->u

            adj[v].push_back(u);
            indegree[u]++;
        }

        return topologicalSort(adj, numCourses, indegree);
    }
};