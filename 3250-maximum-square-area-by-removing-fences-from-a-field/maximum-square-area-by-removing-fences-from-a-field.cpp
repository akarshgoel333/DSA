class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hF, vector<int>& vF) {
        int MOD = 1e9 +7;
        if(m==n){
            long long ans = (long long)(m-1)*(m-1)%MOD;
            return (int)ans;
        }
        unordered_set<int>hcnt;
        hcnt.insert(m-1);
        for(int i=0; i<hF.size(); i++){
            for(int j=0; j<hF.size(); j++){
                if(i!=j) hcnt.insert(abs(hF[i]-hF[j]));
            }
            hcnt.insert(hF[i]-1);
            hcnt.insert(m-hF[i]);
        }
        long long ans = -1;
        if(hcnt.count(n-1)){
            ans = (long long)(n-1)*(n-1)%MOD;
            return (int)ans;
        }
        for(int i=0; i<vF.size(); i++){
            for(int j=0; j<vF.size(); j++){
                if(i!=j && hcnt.count(abs(vF[i]-vF[j]))) ans = max(ans,(long long)abs(vF[i]-vF[j]));
            }
            if(hcnt.count(vF[i]-1)) ans = max(ans,(long long)vF[i]-1);
            if(hcnt.count(n-vF[i])) ans = max(ans,(long long)n-vF[i]);
        }
        if(ans==-1) return -1;
        ans = (long long)ans*ans%MOD;
        return (int)ans;
    }
};