class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int n = lst.size();
        int m = wst.size();
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int route1 = lst[i]+ld[i];
                if(wst[j]<=route1) route1 += wd[j];
                else route1 = wst[j]+wd[j];

                int route2 = wst[j]+wd[j];
                if(lst[i]<=route2) route2 += ld[i];
                else route2 = lst[i]+ld[i];
                ans = min({ans,route1,route2});
            }
        }
        return ans;
    }
};