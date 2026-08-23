class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        int i = lower;
        set<int>s(nums.begin(),nums.end());
        while(i<=upper){
            if(s.count(i)) i++;
            else{
                int low = i;
                while(i<=upper && !s.count(i)){
                    i++;
                }
                int up = i-1;
                ans.push_back({low,up});
            }
        }
        return ans;
    }
};