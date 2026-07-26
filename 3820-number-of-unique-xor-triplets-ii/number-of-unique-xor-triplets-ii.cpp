class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>s;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                s.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int>sp;
        for(auto &n1: s){
            for(auto &n2: nums) sp.insert(n1^n2);
        }
        return sp.size();
    }
};