class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mp;
        for(auto &x: arr){
            mp[x] = 1;
        }
        int var = 1;
        for(auto &[key,val]: mp){
            val = var;
            var++;
        }
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};