class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        bool flag=false;
        int ans = INT_MAX;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]==nums[j] && nums[i]==nums[k]){
                        flag=true;
                        ans = min(ans,abs(i-j)+abs(j-k)+abs(i-k));
                    }
                }
            }
        }
        if(flag) return ans;
        return -1;
    }
};