class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        if(nums[start]==target) return 0;
        int i = 1;
        while(i<n){
            if(i+start<n){
                if(nums[start+i]==target) return i;
            }
            if(start-i>=0){
                if(nums[start-i]==target) return i;
            }
            i++;
        }
        return -1;
    }
};