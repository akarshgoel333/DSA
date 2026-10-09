class Solution {
public:
    int n;
    bool bfs(int u, vector<vector<int>>& graph, vector<int>&vis, int color){
        vis[u] = color;
        queue<int>q;
        q.push(u);
        while(!q.empty()){
            u = q.front();
            q.pop();
            for(auto &v: graph[u]){
                if(vis[v] == vis[u]) return false;
                else if(vis[v]==-1){
                    q.push(v);
                    vis[v] = 1-vis[u];
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1 && !bfs(i,graph,vis,0)) return false;
        }
        return true;
    }
};