class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i]<6) continue;
            int var = 1+nums[i];
            int num = nums[i];
            int cnt = 0;
            for(int j=2; j*j<= num; j++){
                if(num%j==0){
                    int nxt = num/j;
                    cnt++;
                    if(nxt==j) cnt=2;
                    if(cnt>1) break;
                    var += j+nxt;
                }
            }
            if(cnt==1) ans += var;
            cout<<var<<" ";
        }
        return ans;
    }
};