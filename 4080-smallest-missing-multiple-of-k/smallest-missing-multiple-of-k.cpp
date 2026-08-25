class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>s(nums.begin(),nums.end());
        int i=k;
        for(i=k; i<101; i=i+k){
            if(!s.count(i)) return i;
        }
        return i;
    }
};