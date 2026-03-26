class Solution {
public:
    typedef long long ll;
    ll total = 0;

    bool hori(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        unordered_set<ll>s;
        ll top = 0;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                top += grid[i][j];
                s.insert(grid[i][j]);
            }
            ll bottom = total-top;
            ll diff = top-bottom;
            if(diff==0) return true;

            if(diff== (ll)grid[0][0]) return true;
            if(diff== (ll)grid[0][m-1]) return true;
            if(diff== (ll)grid[i][0]) return true;

            if(i>0 && m>1 && s.count(diff)) return true;
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) total += grid[i][j];
        }
        if(hori(grid)) return true;

        reverse(begin(grid),end(grid));
        if(hori(grid)) return true;

        reverse(begin(grid),end(grid));
        vector<vector<int>>transp(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) transp[i][j]=grid[j][i];
        }
        if(hori(transp)) return true;

        reverse(begin(transp),end(transp));
        if(hori(transp)) return true;

        return false;
    }
};