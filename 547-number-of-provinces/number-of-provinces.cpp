class Solution {
public:
    int v;
    void bfs(int u, vector<vector<int>>& isConnected, vector<bool>&vis){
        vis[u]=true;
        queue<int>q;
        q.push(u);
        int node;
        while(!q.empty()){
            node = q.front();
            q.pop();
            for(int i=0; i<v; i++){
                if(isConnected[node][i]==1 && !vis[i]){
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        v = isConnected.size();
        int cnt=0;
        vector<bool>vis(v,false);
        for(int i=0; i<v; i++){
            if(!vis[i]){
                bfs(i,isConnected,vis);
                cnt++;
            }
        }
        return cnt;
    }
};