class Solution {
public:
    void dfs(int u, unordered_map<int,vector<int>>&adj, vector<bool>&vis){
        vis[u]=true;
        for(auto &v: adj[u]){
            if(!vis[v]) dfs(v,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0; i<v; i++){
            for(int j=i+1; j<v; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<bool>vis(v,false);
        for(int i=0; i<v; i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};