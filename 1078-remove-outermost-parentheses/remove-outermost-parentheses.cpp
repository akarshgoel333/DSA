class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string str = "";
        for(char ch: s){
            if(ch=='('){
                if(st.size()!=0){
                    str += ch;
                }
                st.push(ch);
            }
            else{
                if(st.size()!=1){
                    str += ch;
                }
                st.pop();
            }
        }
        return str;
    }
};