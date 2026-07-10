class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathvisited)
    {
            visited[node] = 1;
            pathvisited[node] = 1;

            for(int nei:adj[node])
            {
                if(!visited[nei])
                {
                    if(dfs(nei,adj,visited,pathvisited)) return true;
                }
                else if(pathvisited[nei]) return true;
            }

            pathvisited[node] = 0;

            return false; 

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto& p:prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> visited(numCourses);
        vector<int> pathvisited(numCourses);

        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(dfs(i,adj,visited,pathvisited)) return false;
            }
        }
        return true;
    }
};