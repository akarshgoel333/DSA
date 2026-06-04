class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i=num1; i<=num2; i++){
            if(i<100) continue;
            int num = i;
            while(num>100){
                int a = num%10, b = (num%100)/10;
                int c = (num%1000)/100;
                if(b>a && b>c) ans++;
                else if(b<c && b<a) ans++;
                num /= 10;
            }
        }
        return ans;
    }
};