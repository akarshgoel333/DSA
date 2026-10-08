class Solution {
public:
    bool dfs(int u, unordered_map<int,vector<int>>&adj, vector<bool>&vis, vector<bool> &inRec){
        vis[u]=true;
        inRec[u]=true;
        for(auto &v: adj[u]){
            if(inRec[v]){
                return true;
            }
            if(!vis[v] && dfs(v,adj,vis,inRec)) return true;
        }
        inRec[u]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>>adj;
        for(auto &u: pre){
            adj[u[1]].push_back(u[0]);
        }
        vector<bool>vis(n,false);
        vector<bool>inRec(n,false);
        for(int i=0; i<n; i++){
            if(!vis[i] && dfs(i,adj,vis,inRec)) return false;
        }
        return true;
    }
};