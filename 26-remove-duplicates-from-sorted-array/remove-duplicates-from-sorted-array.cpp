class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int a = 1;
        int var = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] != var) {
                nums[a] = nums[i];
                a++;
                var = nums[i];
            }
        }
        return a;
    }
};