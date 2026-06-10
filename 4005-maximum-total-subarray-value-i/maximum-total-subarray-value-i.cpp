class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto &x: nums){
            mini = min(mini,x);
            maxi = max(maxi,x);
        }
        long long ans = (maxi-mini);
        ans *= k;
        return ans;
    }
};