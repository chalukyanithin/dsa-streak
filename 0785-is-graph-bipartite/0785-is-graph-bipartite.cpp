class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& color,int col,int node)
    {
        color[node] = col;

        for(auto& adj:graph[node])
        {
            if(color[adj]==-1)
            {
                if(!dfs(graph,color,!col,adj)) return false;
            }
            else if(color[adj]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);

        for(int i=0;i<n;i++) color[i]=-1;

        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!dfs(graph,color,0,i)) return false;
            }
        }

        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna