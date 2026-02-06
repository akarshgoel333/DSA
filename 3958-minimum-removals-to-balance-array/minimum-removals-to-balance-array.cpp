class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int j = 0, leng = 0;
        for(int i=0;i<n;i++){
            while((long long)nums[i] > (long long)nums[j]*k){
                j++;
            }
            leng = max(leng, i-j+1);
        }
        return n-leng;
    }
};