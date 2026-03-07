class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int ans1 = 0, ans2 = 0, ans = INT_MAX;
        while(j<2*n){
            char exp1 = j%2 ? '1':'0';
            char exp2 = j%2 ? '0':'1';

            if(s[j%n] != exp1) ans1++;
            if(s[j%n] != exp2) ans2++;

            if(j-i+1>n){
                exp1 = i%2 ? '1':'0';
                exp2 = i%2 ? '0':'1';
                if(s[i%n] != exp1) ans1--;
                if(s[i%n] != exp2) ans2--;
                i++;
            }

            if(j-i+1==n){
                ans = min({ans,ans1,ans2});
            }
            j++;
        }
        return ans;
    }
};