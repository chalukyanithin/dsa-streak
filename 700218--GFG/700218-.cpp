class Solution {
  public:
    bool topo(int V,vector<vector<int>>& adj)
    {
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
        int cnt=0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            cnt++;
            for(auto& n:adj[node])
            {
                indegree[n]--;
                
                if(indegree[n]==0) q.push(n);
            }
        }
        if(cnt==V) return false;
        else return true;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto& e:edges)
        {
            adj[e[1]].push_back(e[0]);
        }
        return topo(V,adj);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna