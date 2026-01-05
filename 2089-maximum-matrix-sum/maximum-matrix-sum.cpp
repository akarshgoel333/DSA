class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        int mini = INT_MAX;
        long long sum = 0;
        int neg = 0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                mini = min(mini,abs(mat[i][j]));
                sum += abs(mat[i][j]);
                if(mat[i][j]<0) neg++;
            }
        }
        if(neg%2) sum -= (2*mini);
        return sum;
    }
};