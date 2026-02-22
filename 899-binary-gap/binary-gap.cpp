class Solution {
public:
    int binaryGap(int n) {
        bitset<32> b(n);
        string binary = b.to_string();
        binary = binary.substr(binary.find('1'));
        int i=0;
        bool flag = false;
        int srt=0;
        int ans=0;
        while(i<binary.length()){
            if(binary[i]=='1'){
                if(flag){
                    ans = max(ans,i-srt);
                    srt=i;
                }
                else{
                    flag=true;
                    srt=i;
                }
            }
            i++;
        }
        return ans;
    }
};