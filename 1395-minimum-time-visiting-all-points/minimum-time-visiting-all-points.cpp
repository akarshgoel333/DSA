class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int inx = points[0][0];
        int iny = points[0][1];
        int ans = 0;
        for(int i=1; i<n; i++){
            int a = abs(inx-points[i][0]);
            int b = abs(iny-points[i][1]);
            inx = points[i][0];
            iny = points[i][1];
            ans += max(a,b);
            // cout<<ans<<" ";
        }
        return ans;
    }
};