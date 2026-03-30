class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        int even = 0;
        int odd = 0;
        for(int i=0; i<n; i++){
            if(i%2==0){
                even += s1[i] - 'a';
                even -= s2[i] - 'a';
            }
            else{
                odd += s1[i] - 'a';
                odd -= s2[i] - 'a';
            }
        }
        if(even!=0 || odd!=0) return false;
        vector<int>eve(26,0);
        vector<int>oddd(26,0);
        for(int i=0; i<n; i++){
            if(i%2==0){
                eve[s1[i]-'a']++;
                eve[s2[i]-'a']--;
            }
            else{
                oddd[s1[i]-'a']++;
                oddd[s2[i]-'a']--;
            }
        }
        for(int i=0; i<26; i++){
            if(eve[i]!=0 || oddd[i]!=0) return false;
        }
        return true;
    }
};