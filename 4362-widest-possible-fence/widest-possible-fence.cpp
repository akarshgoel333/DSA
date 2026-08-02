class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n = planks.size();
        
        map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[planks[i]]+=1;
        }
        
        int ans = 0;
        vector<pair<int,int>>pr(mp.begin(),mp.end());
        int m = pr.size();
        for(int i=0; i<m; i++){
            auto [x,fx] = pr[i];
            for(int j=i+1; j<m; j++){
                auto [y,fy] = pr[j];
                mp[x+y] += min(fx,fy);
            }
            mp[2*x] += fx/2;
        }
        for(auto &[key,val]: mp) ans = max(ans,val);
        return ans;
    }
};