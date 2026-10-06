class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        stack<char>ch;
        int cnt = 0;
        int i = 0;
        while(i<n){
            if(s[i]=='(') ch.push('(');
            else{
                if(!ch.empty()) ch.pop();
                else cnt++;
            }
            i++;
        }
        cnt += ch.size();
        return cnt;
    }
};