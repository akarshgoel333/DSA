class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find (int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;
        if(rank[x_parent] > rank[y_parent]) parent[y_parent] = x_parent;
        else if(rank[x_parent] < rank[y_parent]) parent[x_parent] = y_parent;
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(auto &v: edges){
            if(find(v[0])!=find(v[1])) Union(v[0],v[1]);
        }
        unordered_map<int,long long>mp;
        for(int i=0; i<n; i++){
            mp[find(i)]++;
        }
        long long rem = n, ans = 0;
        for(auto [key,val]: mp){
            ans += val*(rem-val);
            rem -= val;
        }
        return ans;
    }
};