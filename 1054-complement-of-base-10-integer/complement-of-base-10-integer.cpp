class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        if(n==1) return 0;
        int m = log2(n)+1;
        int a = (1<<m) - 1;
        return a-n;
    }
};