class Solution {
public:
    string removeOuterParentheses(string s) {
        int i=0;
        string ans = "";
        for(auto &ch: s){
            if(ch=='(' && i++>0) ans += ch;
            else if(ch==')' && i-->1) ans += ch;
            
        }
        return ans;
    }
};