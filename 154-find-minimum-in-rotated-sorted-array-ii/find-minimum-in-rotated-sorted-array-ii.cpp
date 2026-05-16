class Solution {
public:
    int findMin(vector<int>& nums) {
        for(auto &x: nums){
            if(x<nums[0]) return x;
        }
        return nums[0];
    }
};