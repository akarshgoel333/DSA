class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int ans = INT_MAX, ans1=0;
        while(j<2*n){
            char exp = j%2 ? '1':'0';

            if(s[j%n] != exp) ans1++;

            if(j-i+1>n){
                exp = i%2 ? '1':'0';
                if(s[i%n] != exp) ans1--;
                i++;
            }

            if(j-i+1==n){
                ans = min({ans,ans1,n-ans1});
            }
            j++;
        }
        return ans;
    }
};