class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        int sc = 0;
        for(int i=-1; i<n; i++){
            arr.clear();
            for(int j=0; j<n; j++){
                if(i==j) continue;
                else arr.push_back(nums[j]);
            }
            int m = arr.size();
            if(m<2) continue;

            vector<int>pref(m,0);
            pref[0] = arr[0];
            for(int i=1; i<m; i++){
                pref[i] = __gcd(pref[i-1],arr[i]);
            }
            vector<int>suff(m,0);
            suff[m-1] = arr[m-1];
            for(int i=m-2; i>=0; i--){
                suff[i] = __gcd(suff[i+1],arr[i]);
            }
            int var = 0;
            for(int i=0; i<m-1; i++){
                if(pref[i]==suff[i+1]) var++;
            }
            sc = max(sc,var);
        }
        return sc;
    }
};