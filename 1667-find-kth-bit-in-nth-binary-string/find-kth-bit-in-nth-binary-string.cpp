class Solution {
public:
    char findKthBit(int n, int k) {
        string str = "";
        str += '0';
        for(int i=1; i<n; i++){
            int len = str.length();
            string s = str;
            reverse(s.begin(),s.end());
            int j=0;
            while(j<s.length()){
                if(s[j]=='1') s[j]='0';
                else s[j]='1';
                j++;
            }
            str = str + '1' + s;
        }
        return str[k-1];
    }
};