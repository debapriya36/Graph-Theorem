  // Function to detect cycle in a directed graph.
    
    bool dfs(int node ,vector<int> adj[] ,vector<int>& vis,vector<int>& pathVis )
    {
        vis[node]++;
        pathVis[node]++;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
                if(dfs(it,adj,vis,pathVis))return true;
            }
            else if(vis[it] && pathVis[it])return true;
        }
        pathVis[node]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
    
        int N=2e5;
        vector<int>vis(N,0),pathVis(N,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0){
            if(dfs(i,adj,vis,pathVis))return true;
            }
        }
        return false;
        
    }
