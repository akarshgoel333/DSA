class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0; i<n; i++){
            set<int>cnt;
            int odd=0, eve=0;
            for(int j=i; j<n; j++){
                if(cnt.find(nums[j]) == cnt.end()){
                    if(nums[j]%2==1) odd++;
                    else eve++;
                }
                cnt.insert(nums[j]);
                if(odd==eve){
                    maxi = max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};