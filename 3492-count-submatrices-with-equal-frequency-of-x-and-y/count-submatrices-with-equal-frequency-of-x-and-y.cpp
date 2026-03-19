class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<int>cols(m,0);
        vector<bool>flag(m,false);
        for(int i=0; i<n; i++){
            int rows = 0;
            for(int j=0; j<m; j++){
                if(grid[i][j]=='X'){
                    flag[j]=true;
                    rows++;
                }
                else if(grid[i][j]=='Y') rows--;
                if(j>0 && flag[j-1]) flag[j]=true;
                cols[j] += rows;
                if(cols[j]==0 && flag[j]) ans++;
            }
        }
        return ans;
    }
};