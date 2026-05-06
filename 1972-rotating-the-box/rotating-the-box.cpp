class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxg) {
        int m = boxg.size();
        int n = boxg[0].size();
        vector<vector<char>>ans(n, vector<char>(m,'.'));
        for(int j=0; j<m; j++){
            int obs = n;
            for(int i=n-1; i>=0; i--){
                if(boxg[j][i]=='*'){
                    obs=i;
                    ans[i][m-1-j]='*';
                }
                else if(boxg[j][i]=='#'){
                    ans[obs-1][m-1-j]='#';
                    obs--;
                }
            }
        }
        return ans;
    }
};