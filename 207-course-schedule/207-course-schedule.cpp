class Solution {
public:
    // Intuition: 
    // topological sort (linear ordering of vertices)
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        int n = numCourses;   // nodes
        
        // initializing adjacency list
        vector<int> adj[n];
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        // topological sorting
            
        // 1. calculate indegree's (incoming edges)
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++){
            for(auto adjNode: adj[i])
                indegree[adjNode]++;
        }

        // 2. push node with indegree (=0)
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        // 3. bfs approach
        int cnt = 0;
        while(!q.empty()){

            int node = q.front();
            q.pop();
            cnt++;

            // remove indegree of node which is in topo sort 
            for(auto adjNode: adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }
        
        if(cnt == n)
            return true;
        return false;
    }
};