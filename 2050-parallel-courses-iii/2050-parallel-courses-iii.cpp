class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        //construct the graph 

        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1, 0);

        for (auto &edge : relations) {
            int u = edge[0];
            int v = edge[1];

            //u--->v
            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> completionTime(n+1, 0);

        for (int i = 1; i <=n; i++) {
            completionTime[i] = time[i-1];
        }

        queue<int> que;

        //add course with indegree 0
        for (int i = 1; i <= n; i++) {
            if(indegree[i]==0) {
                que.push(i);
            }
        }

        while (que.empty()==false) {
            int course = que.front();
            que.pop();

            for (int i = 0; i < adj[course].size(); i++) {
                int neighbour = adj[course][i];
                
                completionTime[neighbour] = max(
                    completionTime[neighbour],
                    completionTime[course] + time[neighbour-1]
            );

                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    que.push(neighbour);
                }
            }
        }

        int answer = 0; 
        for (int i = 1; i <=n; i++) {
            answer = max(answer, completionTime[i]);
        }

        return answer;
    }
};