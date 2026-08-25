class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>s(nums.begin(),nums.end());
        int i=1;
        while(true){
            if(!s.count(k*i)) return k*i;
            i++;
        }
        return 0;
    }
};