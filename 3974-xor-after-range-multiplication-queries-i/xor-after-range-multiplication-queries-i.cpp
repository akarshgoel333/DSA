class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        const int mod = 1e9+7;
        for(auto &x: q){
            int l = x[0], r = x[1], k = x[2], v = x[3];
            for(int idx=l; idx<=r; idx+=k){
                nums[idx] = (1LL*nums[idx]*x[3])%mod;
            }
        }
        int ans = 0;
        for(auto &x: nums) ans ^= x;
        return ans;
    }
};