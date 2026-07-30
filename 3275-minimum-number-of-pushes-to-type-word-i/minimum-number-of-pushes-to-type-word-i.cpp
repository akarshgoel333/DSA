class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int divi = n/8;
        int remi = n%8;
        int ans = 0;
        if(divi<1) ans = remi;
        else if(divi<2) ans = 8 + remi*2;
        else if(divi<3) ans = 24 + remi*3;
        else ans = 48 + remi*4;
        return ans;

    }
};