class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>>ans;
        for(int i=0; i<n-2; i++){
            int a = -nums[i];
            int st = i+1, end=n-1;
            while(st<end){
                int b = nums[st];
                int c = nums[end];
                if(b+c==a){
                    ans.insert({-a,b,c});
                    st++;
                    end--;
                }
                else if(b+c<a) st++;
                else end--;
            }
        }
        vector<vector<int>>res;
        for(auto &x: ans){
            res.push_back(move(x));
        }
        return res;
    }
};