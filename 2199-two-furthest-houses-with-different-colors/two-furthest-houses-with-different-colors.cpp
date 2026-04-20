class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int start = colors[0];
        int end = colors[n-1];
        if(start!=end) return n-1;
        int ans = 0;
        int i=n-2;
        while(i>0){
            if(colors[i]!=start){
                ans = max(ans,i);
                break;
            }
            i--;
        }
        i=1;
        while(i<n){
            if(colors[i]!=end){
                ans = max(ans,n-1-i);
                break;
            }
            i++;
        }
        return ans;
    }
};