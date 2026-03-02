class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>endz(n,0);
        for(int i=0; i<n; i++){
            int count =0;
            for(int j=n-1; j>=0 && grid[i][j]==0; j--){
                count++;
            }
            endz[i]=count;
        }

        int steps = 0;
        for(int i=0; i<n; i++){
            int need = n-1-i;
            int j=i;
            while(j<n && endz[j]<need){
                j++;
            }
            if(j==n) return -1;
            steps += (j-i);
            while(j>i){
                swap(endz[j-1],endz[j]);
                j--;
            }
        }
        return steps;
    }
};