class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k) return 0;
        unordered_set<string>sbst;
        int n = s.length();
        for(int i=0; i<=n-k; i++){
            sbst.insert(s.substr(i,k));
        }
        return sbst.size()== (1<<k);
    }
};