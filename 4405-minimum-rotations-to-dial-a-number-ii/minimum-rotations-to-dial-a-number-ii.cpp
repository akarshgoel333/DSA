class Solution {
public:
    int minRotations(int n, string s) {
        int ans = 0;
        vector<int>dial(n);
        int prev = 0;
        for(int i=0; i<n; i++){
            dial[i] = abs(s[i]-'0'-prev);
            dial[i] = min(dial[i],10-dial[i]);
            ans += dial[i];
            prev = s[i]-'0';
        }
        prev = 0;
        int next;
        int diff = 0;
        for(int i=0; i<n-1; i++){
            next = abs(s[n-1]-'0'-prev);
            next = min(next,10-next);
            if(dial[i]-next>diff){
                diff = dial[i]-next;
            }
            prev = s[i]-'0';    
        }
        return ans-diff;
    }
};