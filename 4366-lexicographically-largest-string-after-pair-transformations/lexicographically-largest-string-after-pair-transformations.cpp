class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;
        for(auto &x: nums){
            int q;
            string res = "";
            while(x>0){
                q = log2(x);
                if(q>25) q = 25;
                res += 'a'+q;
                x -= pow(2,q);
            }
            ans.push_back(res);
        }
        return ans;
    }
};