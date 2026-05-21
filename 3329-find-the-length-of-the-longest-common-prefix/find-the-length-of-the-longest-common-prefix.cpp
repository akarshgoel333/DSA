class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m=arr2.size();
        unordered_set<string>s;
        for(auto &x: arr1){
            string str = to_string(x);
            int j = str.length();
            while(j--){
                s.insert(str);
                str.pop_back();
            }
        }
        int ans = 0;
        for(auto &x: arr2){
            string str = to_string(x);
            int j = str.length();
            while(j--){
                if(s.find(str) != s.end()){
                    ans = max(ans,(int)str.length());
                    break;
                }
                str.pop_back();
            }
        }
        return ans;
    }
};