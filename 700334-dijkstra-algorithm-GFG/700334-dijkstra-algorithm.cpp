class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto& e:edges)
        {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V,1e9) , parent(V+1);
        
        for(int i=1;i<=V;i++) parent[i]=i;
        dist[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int dis = it.first;
            int node = it.second;
            
            if(dis > dist[node])
                continue;
            for(auto& n:adj[node])
            {
                int adjNode = n.first;
                int edn = n.second;
                
                if(dis + edn < dist[adjNode])
                {
                    dist[adjNode] = dis+edn;
                    pq.push({dis+edn,adjNode});
                    parent[adjNode] = node;
                }
            }
            
        }
        
        if(dist[V-1]==1e9) return {-1};
        else return dist;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna