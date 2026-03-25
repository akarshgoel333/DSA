class Solution {
public:
    bool chqrow(vector<long long>&rows){
        int n = rows.size();
        long long total = 0;
        for(int i=0; i<n; i++){
            total += rows[i];
        }
        long long pref = 0;
        for(int i=0; i<n-1; i++){
            pref += rows[i];
            if(pref == total-pref) return true;
        }
        return false;
    }
    bool chqcols(vector<long long>&cols){
        int m = cols.size();
        long long total = 0;
        for(int i=0; i<m; i++){
            total += cols[i];
        }
        long long pref = 0;
        for(int i=0; i<m-1; i++){
            pref += cols[i];
            if(pref == total-pref) return true;
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<long long>rows(n,0), cols(m,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int a = grid[i][j];
                rows[i] += a;
                cols[j] += a;
            }
        }
        if(chqrow(rows)) return true;
        return chqcols(cols);
    }
};