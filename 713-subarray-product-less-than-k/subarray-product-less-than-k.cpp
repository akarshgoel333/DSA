class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int st = 0, end = 0;
        int cnt = 0;
        int n = nums.size();
        int prod = 1;
        if(k<=1) return 0;
        while(end<n){
            prod *= nums[end];
            while(prod>=k) prod /= nums[st++];
            cnt += 1+end-st;
            end++;
        }
        return cnt;
    }
};