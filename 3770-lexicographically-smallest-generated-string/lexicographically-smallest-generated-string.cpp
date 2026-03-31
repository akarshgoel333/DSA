class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        string s(n+m-1,'a');
        vector<bool>canChange(n+m-1,true);
        int i=0;
        while(i<n){
            if(str1[i]=='T'){
                int idx=0;
                while(idx<m){
                    if(canChange[i+idx]){
                        canChange[i+idx]=false;
                    }
                    else if(s[i+idx]!=str2[idx]) return "";
                    s[i+idx]=str2[idx];
                    idx++;
                }
            }
            i++;
        }
        i=0;
        while(i<n){
            if(str1[i]=='F' && s.substr(i,m)==str2){
                bool chng=false;
                for(int idx=m-1; idx>=0; idx--){
                    if(canChange[i+idx]){
                        canChange[i+idx]=false;
                        chng=true;
                        s[i+idx]='b';
                        break;
                    }
                }
                if(!chng) return "";
            }
            i++;
        }
        return s;
    }
};