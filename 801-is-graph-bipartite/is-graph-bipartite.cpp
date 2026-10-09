class Solution {
public:
    int n;
    bool dfs(int u, vector<vector<int>>& graph, vector<int>&vis, int color){
        vis[u] = color;
        for(auto &v: graph[u]){
            if(vis[v] == vis[u]) return false;
            else if(vis[v]==-1){
                if(!dfs(v,graph,vis,1-vis[u])) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1 && !dfs(i,graph,vis,0)) return false;
        }
        return true;
    }
};