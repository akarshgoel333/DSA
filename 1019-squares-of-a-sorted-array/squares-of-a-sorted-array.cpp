class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end=n-1;
        vector<int>ans;
        while(st<=end){
            if(abs(nums[st])>=abs(nums[end])){
                ans.push_back(nums[st]*nums[st]);
                st++;
            }
            else{
                ans.push_back(nums[end]*nums[end]);
                end--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};