class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int start=0, end=m-1;
            int firstNeg = m;
            while(start<=end){
                int mid = start + ((end-start)/2);
                if(grid[i][mid]<0){
                    firstNeg = mid;
                    end = mid-1;
                }
                else start=mid+1;
            }
            ans += (m-firstNeg);
        }
        return ans;
    }
};