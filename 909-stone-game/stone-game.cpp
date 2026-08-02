class Solution {
public:
    int t[501][501];
    int solve(vector<int>&piles, int st, int end){
        if(st>end) return 0;
        if(t[st][end] != -1) return t[st][end];
        int take_1 = piles[st] + min(solve(piles,st+1,end-1),solve(piles,st+2,end));
        int take_2 = piles[end] + min(solve(piles,st+1,end-1),solve(piles,st,end-2));
        return t[st][end] = max(take_1,take_2);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(t,-1,sizeof(t));
        int sum = accumulate(piles.begin(),piles.end(),0);
        int alice_sc = solve(piles,0,n-1);
        return alice_sc > (sum/2);
    }
};