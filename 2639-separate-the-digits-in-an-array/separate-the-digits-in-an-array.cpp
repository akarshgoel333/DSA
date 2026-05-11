class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        vector<int>ans;
        while(i<n){
            int x = nums[i];
            vector<int>var;
            while(x>0){
                var.push_back(x%10);
                x /= 10;
            }
            reverse(var.begin(),var.end());
            ans.insert(ans.end(),var.begin(),var.end());
            i++;
        }
        return ans;
    }
};