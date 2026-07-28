class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>alpha(26,0);
        for(auto &ch: s){
            alpha[ch-'a']++;
        }
        string ans = "";
        int odd = -1;
        for(int i=0; i<26; i++){
            int num = alpha[i]/2;
            while(num--) ans += ('a' + i);
            if(alpha[i]%2 != 0){
                odd = i;
            }
            alpha[i] /= 2;
        }
        if(odd>=0) ans += ('a' + odd);
        for(int i=25; i>=0; i--){
            int num = alpha[i];
            while(num--) ans += ('a' + i);
        }
        return ans;
    }
};