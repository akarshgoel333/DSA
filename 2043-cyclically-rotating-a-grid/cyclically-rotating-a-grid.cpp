class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int lay = min(n,m)/2;
        for(int i=0; i<lay; i++){
            int top = i, left = i;
            int right = m-1-i, bottom = n-1-i;
            vector<int>arr;

            for(int j=left; j<=right; j++) arr.push_back(grid[top][j]);
            for(int j=top+1; j<=bottom-1; j++) arr.push_back(grid[j][right]);
            for(int j=right; j>=left; j--) arr.push_back(grid[bottom][j]);
            for(int j=bottom-1; j>=top+1; j--) arr.push_back(grid[j][left]);

            int sz = arr.size();
            int rot = k % sz;
            int idx = rot;

            for(int j=left; j<=right; j++) grid[top][j] = arr[idx%sz], idx++;
            for(int j=top+1; j<=bottom-1; j++) grid[j][right] = arr[idx%sz], idx++;
            for(int j=right; j>=left; j--) grid[bottom][j] = arr[idx%sz], idx++;
            for(int j=bottom-1; j>=top+1; j--) grid[j][left] = arr[idx%sz], idx++;
        }
        return grid;
    }
};