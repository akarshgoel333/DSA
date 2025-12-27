class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        int m = meet.size();
        sort(meet.begin(),meet.end());
        vector<int>cnt(n,0);
        vector<long long>avl(n,0);
        for(int i=0; i<m; i++){
            int str = meet[i][0];
            int end = meet[i][1];
            bool flag = false;

            long long earlyEndTime = LLONG_MAX;
            int earlyEndRoom = 0;

            for(int j=0; j<n; j++){
                if(avl[j]<=str){
                    cnt[j]++;
                    avl[j] = end;
                    flag = true;
                    break;
                }
                if(avl[j]<earlyEndTime){
                    earlyEndTime = avl[j];
                    earlyEndRoom = j;
                }
            }
            if(!flag){
                avl[earlyEndRoom] += (end-str);
                cnt[earlyEndRoom]++;
            }
        }
        int ans = -1;
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(cnt[i]>maxi){
                maxi = cnt[i];
                ans = i;
            }
        }
        return ans;
    }
};