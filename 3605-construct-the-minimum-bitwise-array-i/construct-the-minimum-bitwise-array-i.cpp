class Solution {
public:
    int check(int num){
        int i=1;
        int ans = -1;
        while(i<=num){
            if((i | (i+1)) == num){
                ans = i;
                break;
            }
            i++;
        }
        return ans;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        for(int i=0; i<nums.size(); i++){
            int a = check(nums[i]);
            ans[i] = a;
        }
        return ans;
    }
};