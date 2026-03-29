class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2) return true;
        int a = 0;
        for(int i=0; i<4; i++){
            a += s1[i]-'a';
            a -= s2[i]-'a';
        }
        if(a!=0) return false;
        swap(s2[0],s2[2]);
        if(s1==s2) return true;
        swap(s2[1],s2[3]);
        if(s1==s2) return true;
        swap(s2[0],s2[2]);
        if(s1==s2) return true;
        return false;
    }
};