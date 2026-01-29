class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        int i = 2;
        int j = 2;
        while (j< nums.size()){
            if(nums[i-2]!=nums[j]){
                nums[i++]=nums[j];
            }
            j++;
        }
        return i;
    }
};