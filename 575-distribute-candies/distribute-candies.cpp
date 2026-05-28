class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        set<int>s;
        for(auto &x: candyType) s.insert(x);
        int sz = s.size();
        return min(n/2,sz);
    }
};