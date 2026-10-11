class Solution {
public:
    vector<int>parent,rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int i, int j){
        int xp = find(i);
        int yp = find(j);
        if(xp==yp) return;
        if(rank[xp]>rank[yp]) parent[yp]=xp;
        else if(rank[xp]<rank[yp]) parent[xp]=yp;
        else{
            parent[xp]=yp;
            rank[yp]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& conn) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
            rank[i]=0;
        }
        int comp = n;
        if(conn.size()<n-1) return -1;
        for(auto &v: conn){
            int xp = find(v[0]);
            int yp = find(v[1]);
            if(xp!=yp){
                Union(v[0],v[1]);
                comp--;
            }
        }
        return comp-1;
    }
};