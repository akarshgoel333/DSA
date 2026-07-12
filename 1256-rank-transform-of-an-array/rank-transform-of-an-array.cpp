class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans = arr;
        sort(ans.begin(),ans.end());
        map<int,int> mp;
        int var = 1;
        for(auto &x: ans){
            if(mp.find(x)==mp.end()){
                mp[x] = var;
                var++;
            }
        }
        for(int i=0; i<n; i++){
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};