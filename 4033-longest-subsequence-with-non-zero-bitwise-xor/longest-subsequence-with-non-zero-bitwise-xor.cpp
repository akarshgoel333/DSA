class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        bool nzero = false;

        for(auto &x: nums){
            if(x!=0) nzero = true;
            total ^= x;
        }
        if(total) return n;
        if(!nzero) return 0;
        return n-1;
    }
};