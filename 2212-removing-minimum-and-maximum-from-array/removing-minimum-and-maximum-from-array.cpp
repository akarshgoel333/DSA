class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        int mini = distance(nums.begin(), min_it);
        int maxi = distance(nums.begin(), max_it);
        if(mini>maxi) swap(mini,maxi);
        int ans1 = min(maxi+1,n-mini);
        ans1 = min(ans1,mini+1+n-maxi);
        return ans1;
    }
};