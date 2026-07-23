class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int num = log2(n) + 1;
        if(n<=2) return n;
        return pow(2,num);
    }
};