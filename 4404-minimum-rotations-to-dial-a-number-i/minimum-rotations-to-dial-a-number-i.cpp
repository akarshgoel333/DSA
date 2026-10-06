class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int prev = 0;
        int var;
        for(int i=0; i<s.length(); i++){
            var = int(s[i]-'0');
            var = abs(var-prev);
            ans += min(var,10-var);
            prev = s[i]-'0';
        }
        return ans;
    }
};