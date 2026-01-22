class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        bool flag = is_sorted(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        while(!flag){
            ans++;
            int sum = INT_MAX, pos = -1;
            for(int i=0; i<n-1; i++){
                if(nums[i]+nums[i+1]<sum){
                    sum = nums[i]+nums[i+1];
                    pos = i;
                }
            }
            nums[pos]=sum;
            nums.erase(nums.begin() + (pos + 1));
            n--;
            flag = is_sorted(nums.begin(), nums.end());
        }
        return ans;
    }
};