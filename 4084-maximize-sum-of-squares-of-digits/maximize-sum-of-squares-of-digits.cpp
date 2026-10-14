class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9*num) return "";
        string str = "";
        for(int i=1; i<=num; i++){
            if(sum>=9){
                str += '9';
                sum -= 9;
            }
            else{
                if(sum>=0){
                    str += '0'+sum;
                    sum = 0;
                }
                else str += '0';
            }
        }
        return str;
    }
};