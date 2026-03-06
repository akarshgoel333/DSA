class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        bool flag = false;
        for(int i=0; i<n-1; i++){
            if(flag && s[i]=='1') return false;
            if(s[i]=='1' && s[i+1]=='0') flag=true;
        }
        if(flag && s[n-1]=='1') return false;
        return true;
    }
};