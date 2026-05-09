class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>arr = nums;
        k%=n;
        k = (n-k);
        for(int i=0; i<n; i++){
            nums[i] = arr[(i+k)%n];
        }
        return;
    }
};