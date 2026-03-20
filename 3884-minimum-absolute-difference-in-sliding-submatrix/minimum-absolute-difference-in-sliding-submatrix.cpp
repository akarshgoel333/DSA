class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n-k+1, vector<int> (m-k+1,0));
        for(int i=0; i<=n-k; i++){
            for(int j=0; j<=m-k; j++){
                vector<int> seq;
                for(int p=i; p<i+k; p++){
                    for(int q=j; q<j+k; q++){
                        seq.push_back(grid[p][q]);
                    }
                }
                sort(seq.begin(),seq.end());
                int mini = INT_MAX;
                for(int k=1; k<seq.size(); k++){
                    if(seq[k]!=seq[k-1]) mini = min(mini,seq[k]-seq[k-1]);
                }
                if(mini != INT_MAX) ans[i][j]=mini;
            }
        }
        return ans;
    }
};