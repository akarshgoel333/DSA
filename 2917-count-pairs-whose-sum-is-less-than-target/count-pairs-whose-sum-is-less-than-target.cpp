class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-1; i++){
            int tgt = target-nums[i];
            int a = lower_bound(nums.begin(),nums.end(),tgt) - nums.begin();
            if(a>i) ans += (a-i-1);
            cout<<a<<" ";
        }
        return ans;
    }
};