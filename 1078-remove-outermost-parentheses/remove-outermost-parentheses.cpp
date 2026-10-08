class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string str = "";
        for(char ch: s){
            if(ch=='(' && cnt++>0){
                str += ch;
            }
            else if(ch==')' && cnt-->1){
                str += ch;
            }
        }
        return str;
    }
};