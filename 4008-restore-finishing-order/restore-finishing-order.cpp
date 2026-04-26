class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = order.size();
        set<int>s;
        for(auto &x: friends){
            s.insert(x);
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(s.count(order[i])) ans.push_back(order[i]);
        }
        return ans;
    }
};