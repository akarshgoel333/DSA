class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool>s(101,0);
        for(auto n: nums) s[n]=1;
        int i=k;
        for(i=k; i<101; i=i+k){
            if(!s[i]) return i;
        }
        return i;
    }
};