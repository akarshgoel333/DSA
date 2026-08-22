class Solution {
public:
    bool checkDivisibility(int n) {
        int sumi = 0;
        int prod = 1;
        int a;
        int var = n;
        while(var>0){
            a = var%10;
            sumi += a;
            prod *= a;
            var /= 10;
        }
        return (n%(sumi+prod))==0;
    }
};