class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int mini = INT_MAX;
        long long sum = 0;
        int neg = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mini = min(mini,abs(mat[i][j]));
                sum += abs(mat[i][j]);
                if(mat[i][j]<0) neg++;
            }
        }
        if(neg%2==0) return sum;
        return sum-(2*mini);
    }
};