class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int>count(32,0);
        int MOD = 1e9 + 7;
        for(auto &num: nums){
            for(int i=0; i<32; i++){
                if(num & (1<<i)){
                    count[i]++;
                }
            }
        }
        long long result = 0;
        while(k--){
            long long curr = 0;
            for(int i=0; i<32; i++){
                if(count[i]>0){
                    curr = curr | (1<<i);
                    count[i]--;
                }
            }
            result = (result + (curr*curr))%MOD;
        }
        return result;
    }
};