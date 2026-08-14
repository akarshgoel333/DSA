class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int>mp;
        int n = s.length();
        int end = 0;
        int ans = 0;
        int st = 0;
        while(end<n){
            int keyf = s[end]-'a';
            int keyb = s[st]-'a';
            if(mp[keyf]==2){
                mp[keyb]--;
                st++;
            }
            else{
                mp[keyf]++;
                end++;
                ans = max(ans,end-st);
            }
        }
        ans = max(ans,end-st);
        return ans;
    }
};