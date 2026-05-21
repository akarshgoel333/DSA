class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m=arr2.size();
        unordered_set<int>s;
        for(auto &x: arr1){
            while(x>0){
                s.insert(x);
                x /= 10;
            }
        }
        int ans = 0;
        for(auto &x: arr2){
            while(x>0){
                if(s.find(x) != s.end()){
                    ans = max(ans, (int)log10(x) + 1);
                    break;
                }
                x /= 10;
            }
        }
        return ans;
    }
};