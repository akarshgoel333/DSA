class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sumi = accumulate(nums.begin(),nums.end(),0);
        int k = sumi-x;
        if(k==0) return n;
        if(k<0) return -1;

        int ans = -1;
        int left = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            while(sum>k && left<=i){
                sum -= nums[left++];
            }
            if(sum==k) ans = max(ans,i-left+1);
        }
        if(ans==-1) return -1;
        return n-ans;
    }
};