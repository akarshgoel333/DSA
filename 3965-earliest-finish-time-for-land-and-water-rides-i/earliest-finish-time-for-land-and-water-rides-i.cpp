class Solution {
    int solve(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd){
        int n = lst.size();
        int m = wst.size();
        int ans = INT_MAX;
        int finish1 = INT_MAX;
        for(int i=0; i<n; i++){
            finish1 = min(finish1,lst[i]+ld[i]);
        }
        for(int j=0; j<m; j++){
            ans = min(ans, max(finish1,wst[j])+wd[j]);
        }
        return ans;
    }
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        int lant = solve(lst,ld,wst,wd);
        int watt = solve(wst,wd,lst,ld);
        return min(lant,watt);
    }
};