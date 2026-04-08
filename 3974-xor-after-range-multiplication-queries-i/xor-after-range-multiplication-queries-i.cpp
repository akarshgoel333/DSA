class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        const int mod = 1e9+7;
        for(auto &x: q){
            int idx = x[0];
            while(idx<=x[1]){
                nums[idx] = (1LL*(nums[idx]%mod)*(x[3]%mod))%mod;
                idx += x[2];
            }
        }
        int ans = 0;
        for(auto &x: nums) ans ^= x;
        return ans;
    }
};