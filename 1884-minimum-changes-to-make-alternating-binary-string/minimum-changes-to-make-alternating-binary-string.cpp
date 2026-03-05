class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i%2==0 && s[i]=='1') ans++;
            else if(i%2!=0 && s[i]=='0') ans++;
        }
        return min(ans,n-ans);
    }
};