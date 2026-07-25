class Solution {
public:
    int maxProduct(int n) {
        int maxi1 = 0, maxi2 = 0;
        while(n){
            int var = n%10;
            n /= 10;
            if(maxi1<var){
                maxi2 = maxi1;
                maxi1 = var;
            }
            else if(maxi2<var){
                maxi2 = var;
            }
        }
        return maxi1*maxi2;
    }
};