class Solution {
  public:
    void dfs(vector<vector<int>>& adj,vector<int>& vis,int node,stack<int>& st){
        vis[node]=1;
        
        for(auto& it:adj[node])
        {
            if(!vis[it]) dfs(adj,vis,it,st);
        }
        st.push(node);
    }
    
    void revdfs(vector<vector<int>>& tra,vector<int>& vis,int node){
        vis[node]=1;
        
        for(auto& it:tra[node])
        {
            if(!vis[it]) revdfs(tra,vis,it);
        }
    }
        
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> vis(V,0);
        
        for(auto& e:edges)
        {
            adj[e[0]].push_back(e[1]);
        }
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(adj,vis,i,st);
            }
        }
        
        vector<vector<int>> tra(V);
        
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            for(auto& it:adj[i])
            {
                tra[it].push_back(i);
            }
        }
        
        int scc=0;
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(!vis[node])
            {
                scc++;
                revdfs(tra,vis,node);
            }
        }
        
        return scc;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna