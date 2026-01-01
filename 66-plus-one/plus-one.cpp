class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1]!=9){
            digits[n-1]++;
            return digits;
        }
        int cnt = 0;
        bool flag = false;
        for(int i=n-1; i>=0; i--){
            if(digits[i]==9){
                if(i!=0) cnt++;
                else{
                    digits[i]=1;
                    flag=true;
                }
            } 
            else{
                if(digits[i+1]==9) digits[i]++;
                break;
            }
        }
        for(int a = n-cnt; a<n; a++){
            digits[a] = 0;
        }
        if(flag) digits.push_back(0);
        
        return digits;
    }
};