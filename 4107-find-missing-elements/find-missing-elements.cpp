class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int>s;
        for(auto &x: nums) s.insert(x);
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        vector<int>ans;
        while(low!=high){
            if(!s.count(low)) ans.push_back(low);
            low++;
        }
        return ans;
    }
};