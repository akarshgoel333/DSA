class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& ivl) {
        int n = ivl.size();
        priority_queue<int, vector<int>, greater<>> pq;
        sort(ivl.begin(),ivl.end());
        int cnt = 0;
        pq.push(ivl[0][1]);
        for(int i=1; i<n; i++){
            while(!pq.empty() && pq.top()<ivl[i][0]){
                pq.pop();
            }
            cnt += pq.size();
            pq.push(ivl[i][1]);
        }
        return cnt;
    }
};