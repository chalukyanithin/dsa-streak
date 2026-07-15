class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j)
    {
        vis[i][j]=1;
        int n =grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;

        q.push({i,j});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

                for(int i=0;i<4;i++)
                {
                    int nrow = row+dr[i];
                    int ncol = col+dc[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' 
                        && vis[nrow][ncol]==0)
                        {
                            vis[nrow][ncol]=1;
                            q.push({nrow,ncol});
                        }
                }
            }
        }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    cnt++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna