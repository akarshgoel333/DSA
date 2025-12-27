class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>ans;
        vector<int>mp(2);
        for(int i=0; i<nums.size(); i++){
            int ab = target - nums[i];
            if(ans.find(ab)!=ans.end()){
                mp[0] = i;
                mp[1] = ans[ab];
            }
            ans[nums[i]]=i;
        }
        return mp;
    }
};