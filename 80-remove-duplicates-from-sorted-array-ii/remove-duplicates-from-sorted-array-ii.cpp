class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int a = 1;
        int var = nums[0];
        bool flag = false;
        for(int i=1; i<n; i++){
            if(nums[i] == var && !flag) {
                nums[a++] = nums[i];
                var = nums[i];
                flag = true;
            }
            else if(nums[i]!=var){
                nums[a++]=nums[i];
                var=nums[i];
                flag=false;
            }
        }
        return a;
    }
};