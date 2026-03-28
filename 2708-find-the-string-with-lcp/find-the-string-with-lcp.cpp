class Solution {
public:
    vector<vector<int>> check(string &s){
        int n = s.length();
        vector<vector<int>>lcp(n,vector<int>(n,0));
        for(int i=0; i<n; i++){
            if(s[i]==s[n-1]){
                lcp[i][n-1]=1;
                lcp[n-1][i]=1;
            }
        }
        for(int i=n-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                if(s[i]==s[j]) lcp[i][j]=1+lcp[i+1][j+1];
                else lcp[i][j]=0;
            }
        }
        return lcp;
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n,'$');
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(lcp[j][i]!=0){
                    s[i] = s[j];
                    break;
                }
            }
            if(s[i]=='$'){
                vector<bool>flag(26,false);
                for(int j=0; j<i; j++){
                    if(lcp[j][i]==0) flag[s[j]-'a']=true;
                }
                for(int j=0; j<26; j++){
                    if(!flag[j]){
                        s[i] = j + 'a';
                        break;
                    }
                }
            }
            if(s[i]=='$') return "";
        }
        return (check(s)==lcp) ? s:"";
    }
};