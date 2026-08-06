class Solution {
public:
    int smallestNumber(int n, int t) {
        int prod = 1;
        int ans = n;
        int var = ans;
        while(true){
            prod = 1;
            var = ans;
            while(var){
                prod *= (var%10);
                var /= 10;
            }
            if(prod%t==0) return ans;
            ans++;
        }
        return ans;
    }
};