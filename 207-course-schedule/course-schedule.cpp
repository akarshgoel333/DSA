class Solution {
public:
    // void dfs(int u, unordered_map<int,vector<int>>&adj, vector<bool>&vis, bool &cyc){
    //     if(cyc) return;
    //     vis[u]=true;
    //     for(auto &v: adj[u]){
    //         if(vis[v]){
    //             cyc=true;
    //             return;
    //         }
    //         dfs(v,adj,vis,cyc);
    //     }
    // }
    bool canFinish(int n, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>>adj;
        for(auto &u: pre){
            adj[u[1]].push_back(u[0]);
        }
        vector<int>indeg(n,0);
        for(int i=0; i<n; i++){
            for(auto &v: adj[i]) indeg[v]++;
        }
        queue<int>q;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(indeg[i]==0){
                q.push(i);
                cnt++;
            }
        }
        int node;
        while(!q.empty()){
            node = q.front();
            q.pop();
            for(auto &v: adj[node]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                    cnt++;
                }
            }
        }
        return cnt==n;
        // vector<bool>vis(n,false);
        // bool cyc = false;
        // for(int i=0; i<n; i++){
        //     if(!vis[i]) dfs(i,adj,vis,cyc);
        //     if(cyc) return false;
        // }
        // return true;
    }
};