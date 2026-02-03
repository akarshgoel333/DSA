class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(nums[1]<=nums[0]) return false;
        bool inc = true;
        int cnt = 0;
        for(int i=2; i<n; i++){
            if(nums[i]==nums[i-1]) return false;
            if(nums[i]<nums[i-1] && inc){
                inc=false;
                cnt++;
            }
            else if(nums[i]>nums[i-1] && !inc){
                inc=true;
                cnt++;
            }
            if(cnt>2) return false;
        }
        if(cnt==2) return true;
        else return false;
    }
};