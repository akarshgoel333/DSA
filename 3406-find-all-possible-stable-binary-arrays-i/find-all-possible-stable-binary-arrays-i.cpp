class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>> dp(zero+1,vector<vector<long long>>(one+1, vector<long long>(2)));
        int mod = 1e9+7;
        dp[0][0][1]=1;
        dp[0][0][0]=1;
        for(int i=0; i<=zero; i++){
            for(int j=0; j<=one; j++){
                if(i==0 && j==0) continue;
                long long result = 0;
                for(int len=1; len<=min(limit,i); len++){
                    result = (result + dp[i-len][j][0])%mod;
                }
                dp[i][j][1]=result;
                result = 0;
                for(int len=1; len<=min(limit,j); len++){
                    result = (result + dp[i][j-len][1])%mod;
                }
                dp[i][j][0]=result;
            }
        }
        return (dp[zero][one][0]+dp[zero][one][1])%mod;
    }
};