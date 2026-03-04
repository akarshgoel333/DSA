class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int>rows(n,0);
        vector<int>cols(m,0);
        for(int i=0; i<n; i++){
            int rowsum = 0;
            for(int j=0; j<m; j++){
                rowsum += mat[i][j];
            }
            rows[i]=rowsum;
        }
        for(int i=0; i<m; i++){
            int colsum = 0;
            for(int j=0; j<n; j++){
                colsum += mat[j][i];
            }
            cols[i]=colsum;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1){
                    if(rows[i]==1 && cols[j]==1) ans++;
                }
            }
        }
        return ans;
    }
};