class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>ans;
        for(int i=0; i<nums.size(); i++){
            int ab = target - nums[i];
            if(ans.find(ab)!=ans.end()) return {i,ans[ab]};
            ans[nums[i]]=i;
        }
        return {-1,-1};
    }
};