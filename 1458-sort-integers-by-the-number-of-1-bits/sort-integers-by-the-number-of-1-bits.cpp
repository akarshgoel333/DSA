class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int,vector<int>>ans;
        for(int i=0; i<arr.size(); i++){
            int x = __builtin_popcount(arr[i]);
            ans[x].push_back(arr[i]);
        }
        vector<int> ans1;
        for(auto [key,val]: ans){
            for (int x : val) {
                ans1.push_back(x);
            }
        }
        return ans1;
    }
};