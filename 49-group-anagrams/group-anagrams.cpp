class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> temp = strs;
        unordered_map<string, int> mp;
        int i = 0;
        for(auto &s: temp){
            sort(s.begin(),s.end());
            if(mp.find(s) == mp.end()){
                mp[s] = i;
                i++;
            }
        }
        vector<vector<string>> ans(i);
        for(int j=0; j<n; j++){
            int value = mp[temp[j]];
            ans[value].push_back(strs[j]);
        }
        return ans;
    }
};