class Solution {
public:
    void validBracks(int left, int right, int n, vector<string> &ans, string &temp){
        if(left+right==(2*n)){
            ans.push_back(temp);
            return;
        }
        if(left<n){
            temp.push_back('(');
            validBracks(left+1,right,n,ans,temp);
            temp.pop_back();
        }
        if(left>right){
            temp.push_back(')');
            validBracks(left,right+1,n,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        validBracks(0,0,n,ans,temp);
        return ans;
    }
};