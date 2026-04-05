class Solution {
public:
    string decodeCiphertext(string text, int rows) {
        int n = text.size();
        int cols = n/rows;
        if(rows == 1) return text;
        string ans = "";
        for(int i=0; i<cols; i++){
            for(int j=0; i+j<n; j+=(cols+1)){
                ans += text[i+j];
            }
        }
        while(!ans.empty() && ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};