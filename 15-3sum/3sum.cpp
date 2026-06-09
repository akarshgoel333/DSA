class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int a = -nums[i];
            int st = i+1, end=n-1;
            while(st<end){
                int b = nums[st];
                int c = nums[end];
                if(b+c==a){
                    ans.push_back({-a,b,c});
                    while(st<end && nums[st]==b) st++; 
                    while(st<end && nums[end]==c) end--;
                }
                else if(b+c<a) st++;
                else end--;
            }
        }
        
        return ans;
    }
};