class Solution {
public:
    void solve(vector<string> &ans, string s, int left, int right, int &n){
        if(left==n){
            while(right<n){
                s += ')';
                right++;
            }
            ans.push_back(s);
            return;
        }

        solve(ans,s + '(',left+1,right,n);
        if(left>right) solve(ans,s + ')',left,right+1,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        solve(ans,s,0,0,n);
        return ans;
    }
};