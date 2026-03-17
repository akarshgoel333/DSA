class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> prev;
        int ans = 0;
        for(int i=0; i<n; i++){
            vector<pair<int,int>> curr;
            vector<bool> seen(m,false);
            for(auto [h,col]: prev){
                if(matrix[i][col]==1){
                    curr.push_back({h+1,col});
                    seen[col]=true;
                }
            }
            for(int j=0; j<m; j++){
                if(seen[j]==false && matrix[i][j]==1) curr.push_back({1,j});
            }
            for(int i=0; i<curr.size(); i++){
                int H = curr[i].first;
                int B = i+1;
                ans = max(ans, H*B);
            }
            prev = curr;
        }
        return ans;
    }
};