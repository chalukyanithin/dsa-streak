class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto& e:edges)
        {
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> indegree(V);
        
        for(int i=0;i<V;i++)
        {
            for(auto& it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> res;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(auto& it:adj[node])
            {
                indegree[it]--;
                
                if(indegree[it]==0) q.push(it);
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna