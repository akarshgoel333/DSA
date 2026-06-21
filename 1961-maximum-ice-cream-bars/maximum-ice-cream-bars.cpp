class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int m = *max_element(costs.begin(),costs.end());
        vector<int>freq(m+1,0);
        for(auto &x: costs){
            freq[x]++;
        }
        long long ans = 0;
        for(int i=0; i<=m; i++){
            if(coins<=0) break;
            if(freq[i]!=0 && coins>=i){
                long long total = 1LL*i*freq[i];
                if(coins>=total){
                    coins -= total;
                    ans += freq[i];
                }
                else{
                    ans += (coins/i);
                    coins = 0;
                }
            }
        }
        return ans;
    }
};