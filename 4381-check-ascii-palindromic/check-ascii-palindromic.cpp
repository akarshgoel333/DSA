class Solution {
public:
    bool isPalindromic(string s) {
        int n = s.length();
        int i = 0;
        string pal = "";
        while(i<n){
            int val = s[i]-'a';
            val += 97;
            string conv = bitset<8>(val).to_string();
            pal += conv; 
            i++;
        }
        n = pal.length();
        i = 0;
        while(i<n/2){
            if(pal[i]!=pal[n-i-1]) return false;
            i++;
        }
        return true;
    }
};