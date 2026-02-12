class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0; i<n; i++){
            vector<int>freq(26,0);
            int dist = 0;
            int mxfrq = 0;
            for(int j=i; j<n; j++){
                int idx = s[j]-'a';
                if(freq[idx]==0) dist++;
                freq[idx]++;
                mxfrq = max(mxfrq,freq[idx]);
                if((j-i+1)==(dist*mxfrq)) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};