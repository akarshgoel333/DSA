class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int activ = 0;
        vector<int>zero;
        int var = 0;
        for(auto &ch: s){
            if(ch=='1'){
                activ++;
                if(var){
                    zero.push_back(var);
                    var = 0;
                }
            }
            else{
                var++;
            }
        }
        if(var) zero.push_back(var);
        int ans = activ;
        for(int i=1; i<zero.size(); i++){
            var = zero[i-1]+zero[i];
            ans = max(ans,(activ+var));
        }
        return ans;
    }
};