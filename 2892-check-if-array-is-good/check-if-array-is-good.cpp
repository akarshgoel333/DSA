class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>2 || nums[i]>n-1) return false;
            else if(mp[nums[i]]>1 && nums[i]!=n-1) return false;
        }
        return true;
    }
};