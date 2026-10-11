class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int,vector<int>>adj;
        int m = relations.size();
        vector<int>indeg(n+1,0);
        for(int i=0; i<m; i++){
            int u = relations[i][0]-1;
            int v = relations[i][1]-1;
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int>prev(n,0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &ed: adj[node]){
                indeg[ed]--;
                if(indeg[ed]==0) q.push(ed);
                prev[ed] = max(prev[ed],prev[node]+time[node]);
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) ans = max(ans,prev[i]+time[i]);
        return ans;
    }
};