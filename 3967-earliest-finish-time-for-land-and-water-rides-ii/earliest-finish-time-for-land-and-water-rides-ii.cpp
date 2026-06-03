class Solution {
    int solve(vector<int>& lt, vector<int>& ld, vector<int>& wt, vector<int>& wd){
        int n = lt.size(), m = wt.size();
        int finish1 = INT_MAX;
        for(int i=0; i<n; i++){
            finish1 = min(finish1,lt[i]+ld[i]);
        }
        int ans = INT_MAX;
        for(int i=0; i<m; i++){
            ans = min(ans,max(finish1,wt[i])+wd[i]);
        }
        return ans;
    }
public:
    int earliestFinishTime(vector<int>& lt, vector<int>& ld, vector<int>& wt, vector<int>& wd) {
        int l1 = solve(lt,ld,wt,wd);
        int w1 = solve(wt,wd,lt,ld);
        return min(l1,w1);
    }
};