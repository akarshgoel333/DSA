class Solution {
public:
    bool hasAlternatingBits(int n) {
        int m = log(n)/log(2);
        m++;
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