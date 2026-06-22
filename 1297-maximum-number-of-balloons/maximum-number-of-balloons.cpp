class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(5,0);
        for(auto &ch: text){
            if(ch=='b') freq[0]++;
            else if(ch=='a') freq[1]++;
            else if(ch=='l') freq[2]++;
            else if(ch=='o') freq[3]++;
            else if(ch=='n') freq[4]++;
        }
        int ans = INT_MAX;
        freq[2] /= 2;
        freq[3] /= 2;
        for(int i=0; i<5; i++){
            ans = min(ans,freq[i]);
        }
        return ans;
    }
};