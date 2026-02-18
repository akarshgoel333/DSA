class Solution {
public:
    bool hasAlternatingBits(int n) {
        int m = log2(n) + 1;
        int ans = 0;
        for(int i=0; i<m; i++){
            if(i%2==0) ans = (ans*2)+1;
            else ans *= 2;
            cout<<ans<<" ";
        }
        if(ans == n) return true;
        return false;
    }
};