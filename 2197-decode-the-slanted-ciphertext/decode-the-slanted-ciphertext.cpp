class Solution {
public:
    string decodeCiphertext(string text, int rows) {
        int cols = text.size()/rows;
        vector<vector<char>>cipher(rows, vector<char>(cols));
        int a=0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cipher[i][j] = text[a];
                a++;
            }
        }
        string ans = "";
        for(int i=0; i<cols; i++){
            for(int j=0; j<rows && i+j<cols; j++){
                ans += cipher[j][i+j];
            }
        }
        while(!ans.empty() && ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};